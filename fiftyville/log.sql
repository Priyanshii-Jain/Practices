-- Keep a log of any SQL queries you execute as you solve the mystery --

--Let's start the investigation from crime scene report table--
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year = 2021 AND street = "Humphrey Street";

--Now to get the name and statements of the witnesses, lets see interviews table--
SELECT name,transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2021;

--By looking at transcripts we concluded that Ruth, Eugene and Raymond mentioned bakery in their trancript--
--Ruth mentioned that theif exits from the car after 10 mins of the theft so lets look at the license plate of the car in bakery_security_logs table--
SELECT activity,license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10;

--lets find the owner of the car in people table as we got the license_plate of the cars that took exit within 10 mins of the theft --
SELECT name,phone_number,passport_number FROM people WHERE license_plate = (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute = 18 AND activity = "exit");

--The owner of the cars who exited the location within 10 mins of the theft were discovered by running the query with different minutes value(e.g. 16,18,19,20,21,23)--
--suspects: Vanessa, Bruce, Luca, Sofia, Iman, Diana

--Eugene mentioned that the theif withdrew money from the atm--
SELECT account_number,amount,transaction_type FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2021 AND atm_location = "Leggett Street";

-- let's find the account names of those transactions from the bank based on their transaction detials--
SELECT name, atm_transactions.amount, atm_transactions.account_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year=2021
AND atm_transactions.month=7
AND atm_transactions.day=28
AND atm_transactions.atm_location='Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';

--Suspects: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista

--According to Raymond the theif is leaving fiftyville from the earliest flight next day--
--Let's find out the name and abbreviation of the airport at Fiftyville--
SELECT abbreviation,full_name FROM airports WHERE city = "Fiftyville";

--Name of the airport is "Fiftyville Regional Airport" and abbrv.-"CSF"--
--Lets find out the list of flights leaving fiftyville on 29 and order them by hour and minutes to find the earliest flight--
SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = (
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour, flights.minute;

--The earliest flight is scheduled on 8:20 to New York and flight id is 36. New York might be the place where theif escaped--
--let's check people boarding on this flight on 29 July--
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
ORDER BY passengers.passport_number;

--Suspects: Bruce, Luca--
--Now we need to find the accomplice who bought the tickets and also find theif out of bruce and luca--
--let's check the names of the callers and order them by duration--
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
--So the caller and the theif is Bruce, because his name is on the list of callers and luca isn't there--

--now let's find out the accomplice and check the name of the receiver by matching th call duration of bruce and the receiver--
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
--Since Robin is the only one whose call duration matches with Bruce's call duration so Robin is the accomplice--


--So finally we solved the mystery--
--where Bruce is theif and Robin is his accomplice and bruce is escaped to New York--





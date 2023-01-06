import cs50

# prompt the user to input change
while True:
    dollars = cs50.get_float("Change owed: ")
    if dollars > 0:
        break
# convert dollar into cents
cents = round(dollars * 100)

# initiate counting variable
coins = 0

# start counting
while cents >= 25:
    cents -= 25
    coins += 1

while cents >= 10:
    cents -= 10
    coins += 1

while cents >= 5:
    cents -= 5
    coins += 1

while cents >= 1:
    cents -= 1
    coins += 1

# print the results
print(f"{coins}")


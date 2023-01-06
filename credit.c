#include <cs50.h>
#include <stdio.h>
//#include <math.h>

int main(void)
{
    long cn;

    do
    {
        cn = get_long("Number: ");
    }
    while (cn < 0);
    // we will see




    int checksum = 0;

    {
        // 2nd digit ** henceforth all digit placement from right to left //
        checksum += (((cn / 10) % 10) * 2) / 10;
        checksum += (((cn / 10) % 10) * 2) % 10;
    }
    {
        // 4th digit //
        checksum += (((cn / 1000) % 10) * 2) / 10;
        checksum += (((cn / 1000) % 10) * 2) % 10;
    }
    {
        // 6th digit  //
        checksum += (((cn / 100000) % 10) * 2) / 10;
        checksum += (((cn / 100000) % 10) * 2) % 10;
    }
    {
        // 8th digit //
        checksum += (((cn / 10000000) % 10) * 2) / 10;
        checksum += (((cn / 10000000) % 10) * 2) % 10;
    }
    {
        // 10th digit //
        checksum += (((cn / 1000000000) % 10) * 2) / 10;
        checksum += (((cn / 1000000000) % 10) * 2) % 10;
    }
    {
        // 12th digit //
        checksum += (((cn / 100000000000) % 10) * 2) / 10;
        checksum += (((cn / 100000000000) % 10) * 2) % 10;
    }
    {
        // 14th digit //
        checksum += (((cn / 10000000000000) % 10) * 2) / 10;
        checksum += (((cn / 10000000000000) % 10) * 2) % 10;
    }
    {
        // 16th digit //
        checksum += (((cn / 1000000000000000) % 10) * 2) / 10;
        checksum += (((cn / 1000000000000000) % 10) * 2) % 10;
    }
    {
        //  1st digit //
        checksum += cn % 10;
    }
    {
        // 3rd digit //
        checksum += (cn / 100) % 10;
    }
    {
        // 5th digit //
        checksum += (cn / 10000) % 10;
    }
    {
        // 7th digit //
        checksum += (cn / 1000000) % 10;
    }
    {
        // 9th digit //
        checksum += (cn / 100000000) % 10;
    }
    {
        // 11th digit //
        checksum += (cn / 10000000000) % 10;
    }
    {
        // 13th digit //
        checksum += (cn / 1000000000000) % 10;
    }
    {
        // 15th digit //
        checksum += (cn / 100000000000000) % 10;
    }

    if (checksum % 10 == 0 && (cn / 1000000000000000) % 10 == 5
            && (cn / 100000000000000) % 10 >= 1
            && (cn / 100000000000000) % 10 <= 5)
    {
        printf("MASTERCARD\n");
    }
    else if (checksum % 10 == 0 && (cn / 1000000000000) % 10 == 4)
    {
        printf("VISA\n");
    }
    else if (checksum % 10 == 0 && (cn / 1000000000000000) % 10 == 4)
    {
        printf("VISA\n");
    }
    else if (checksum % 10 == 0 && (cn / 100000000000000) % 10 == 3
            && (cn / 10000000000000) % 10 == 4)
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 && (cn / 100000000000000) % 10 == 3
            && (cn / 10000000000000) % 10 == 7)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;

}
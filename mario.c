#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
 //to make sure the input entered should be integer and more than 0 and less than 8
    while (n > 8 || n < 1);


// to initiate new row

    for (int i = 0; i < n; i++)
    {

// for inserting dots to acheive right alignment of hashes
//  for ( int d = 0; d > i - n + 1; d--)
// {
//  printf(".");
//}
// remove dots and make our pyramid right aligned
        for (int d = 0; d > i - n + 1; d--)
        {
            printf(" ");
        }
// to print hash columns
        for (int h = 0; h < i + 1; h++)
        {
            printf("#");
        }
// to keep space
        for (int j = 0 ; j >= 0; j--)
        {
            printf("\n");

        }

    }




}
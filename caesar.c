#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Run the programme with just one command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check wheather argv[1] is digit or not
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //make argv[1] an int i.e. key
    int key = atoi(argv[1]);

    //ask user to input plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    //go through each letter of the input
    int (i);
    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            //encipher text with the calculation
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");


}
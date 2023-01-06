#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
//int round();

int main(void)
{
    //Get input from user
    string text = get_string("Text: ");
    //printf("%s\n", text);

    //Count the number of letters, word and sentences in a text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //calculate average letters and sentences per 100 words
    float T = letters;
    float D = words;
    float C = sentences;
    float L = (T / D * 100);
    float S = (C / D * 100);
    //put the values in the formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    int ans = round(index);
    if (index < 1)    //
    {
        //if index is less than 1, print 'Before Grade 1'
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        //if index is greater than 16, print 'Grade 16+'
        printf("Grade 16+\n");
    }
    else
    {
        //else if index is any other digit, print Grade index(digit)
        printf("Grade %i\n", index);
    }

}
int count_letters(string text)
{
    int letters = 0;
    int(i);
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    //printf("%i\n", letters);
    return letters;
}
int count_words(string text)
{
    int words = 1;
    int(i);
    for (i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    //printf("%i\n", words);
    return words;
}
int count_sentences(string text)
{
    int sentences = 0;
    int(i);
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    //printf("%i\n", sentences);
    return sentences;
}
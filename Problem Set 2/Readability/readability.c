//********************************************************************************************************************
// Implement a program that computes the approximate grade level needed to comprehend some text, per the Coleman-Liau index.
// index = 0.0588 * L - 0.296 * S - 15.8
// Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
//********************************************************************************************************************
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //User Input
    string text = get_string("Text: "); // Declare variable

    //variables
    int number_character;
    int letters = 0;
    int number_spaces, count_spaces = 0;
    int number_sentences, count_sentences = 0;
    char spaces[] = " ";
    char sentences[] = "!?.";

    // Count letters
    for (number_character = 0; number_character < strlen(text); number_character++)
    {
        if (isalpha(text[number_character]))
        {
            letters++;
        }
    }

    // Count spaces
    for (number_character = 0; number_character < strlen(text); number_character++)
    {
        for (number_spaces = 0; number_spaces < strlen(spaces); number_spaces++)
        {
            if (text[number_character] == spaces[number_spaces])
            {
                count_spaces++;
            }
        }
    }

    // Count Words
    int words = count_spaces + 1; // Words = Total Spaces + 1

    // Count Sentences
    for (number_character = 0; number_character < strlen(text); number_character++)
    {
        for (number_sentences = 0; number_sentences < strlen(sentences); number_sentences++)
        {
            if (text[number_character] == sentences[number_sentences])
            {
                count_sentences++;
            }
        }
    }

    // Values
    float L = (float) letters / words * 100;
    float S = (float) count_sentences / words * 100;

    // Formula Coleman-Liau index
    float index  = (0.0588 * L) - (0.296 * S) - 15.8;

    // Convert float to int
    int rounded_index = round(index);

    //If the index is greater than or equal to 16, then print Grade 16+
    if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }

    //If the index is less than 1, print before grade 1
    else if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }

    //Else print the index given by the coleman-liau index computation above
    else
    {
        printf("Grade %i\n", rounded_index);
    }

    return 0;
}

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{   
    // Check it's a single command-line argument and if character is decimal digit
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {   
        //variables
        int number_character, number_int, count_int = 0;
        char numbers[] = "0123456789";
        
        // Count if is a number
        for (number_character = 0; number_character < strlen(argv[1]); number_character++)
        {
            for (number_int = 0; number_int < strlen(numbers); number_int++)
            {
                if (argv[1][number_character] == numbers[number_int])
                {
                    count_int++;
                }
            }
        }
        // Check a non-negative integer
        if (count_int < strlen(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Convert string to int "integer"
            int key = atoi(argv[1]);
        
            // prompt user for a code to encrypt
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                //check if the letter is uppercase or lowercase then convert
                // Lowercase //a = 97 z = 122
                if islower(plaintext[i])
                {
                    printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
                }
                // Uppercase // A = 65 Z = 90
                else if isupper(plaintext[i])
                {
                    printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
                }
                    
                //if neither then just print whatever it is
                else
                {
                    printf("%c", plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}

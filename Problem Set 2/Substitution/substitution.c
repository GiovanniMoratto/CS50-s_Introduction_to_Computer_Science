#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool validate_key(int argc, string argv[]); // Declare function validation

int main(int argc, string argv[]) // ** Get key **
{
    // ** Validate key **
    if (validate_key(argc, argv) == 1)
    {
        return 1;
    }
    else
    {
        // ** Get Plaintext **
        string plaintext = get_string("plaintext: "); // prompt user for a code to encrypt
        string diff = argv[1];

        for (int i = 'A'; i <= 'Z'; i++)
        {
            diff[i - 'A'] = toupper(diff[i - 'A']) - i;
        }
        printf("ciphertext: ");
        
        // ** Encipher **
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {
                plaintext[i] = plaintext[i] + diff[plaintext[i] - (isupper(plaintext[i]) ? 'A' : 'a')];
            }
            // ** Print Ciphertext **
            printf("%c", plaintext[i]);
        }
        printf("\n");
        return 0;
    }
}
// ** Validate key **
bool validate_key(int argc, string argv[])
{
    //************************************************************
    if (argc != 2) // Check it's a single command-line argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //************************************************************
    string s = argv[1];
    int lenght = strlen(s); // Count number of caracters and convert string to int

    if (lenght != 26) // Check lenght
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //************************************************************
    // Check for letters and repeated
    int freq[26] = {0};
    for (int i = 0; i < lenght; i++)
    {
        if (!isalpha(s[i])) // check for alphabets
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        int index = toupper(s[i]) - 'A'; // Changes to uppercase
        if (freq[index] > 0) // Check for repeated
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        freq[index]++;
    }
    //************************************************************
    // if we passed both tests, we've good!
    return 0;
}

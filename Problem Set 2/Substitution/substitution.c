#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool validate_key(int argc, string argv[]); // Declare function validation
void string_to_uppercase(string argv[1]); // Declare function Uppercase

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
    int lenght = strlen(argv[1]); // Count number of caracters and convert string to int

    if (lenght != 26) // Check lenght
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //************************************************************
    // Check for letters
    int  txt = 0, l;

    for (l = 0; (argv[1])[l] != '\0'; l++)
    {
        // check for alphabets
        if (isalpha((argv[1])[l]) != 0)
        {
            txt++;
        }
    }
    if (txt != lenght)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //************************************************************
    // Check for repeated
    for (int i = 0; i < lenght; i++) //Counts each character present in the string
    {
        string_to_uppercase(argv); // Converte a string
        string upper = argv[1];
        int count;

        count = 1;
        for (int j = i + 1; j < lenght; j++)
        {
            if (upper[i] == upper[j] && upper[i] != ' ')
            {
                count++;
                //Set string[j] to 0 to avoid printing visited character
                upper[j] = '0';
            }
        }
        //A character is considered as duplicate if count is greater than 1
        if (count > 1 && upper[i] != '0')
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //************************************************************
    // if we passed both tests, we've good!
    return 0;
}

// The function changes all letters to uppercase
void string_to_uppercase(string argv[1])
{
    int i;
    string texto = (argv[1]);

    //Counts each character present in the string
    for (i = 0; texto[i] != '\0'; i++)
    {
        //check if the letter is uppercase or lowercase then convert
        if (texto[i] >= 97 && texto[i] <= 122) // Lowercase //a = 97 z = 122 ascii
        {
            texto[i] -= 32; // Change to upper
        }
    }
}

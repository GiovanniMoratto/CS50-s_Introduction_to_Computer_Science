#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    long creditCardNumber; // Declare variable

    do
    {
        creditCardNumber = get_long("Number: \n"); //take user input
    }
    while (creditCardNumber <= 0);

    long workingCC = creditCardNumber; // Declare variable
    int sum = 0; // Declare variable
    int count = 0; // Declare variable
    long divisor = 10; // Declare variable
    char result[11]; // Declare variable

    // 1st case
    while (workingCC > 0) // while loop
    {
        int lastDigit = workingCC % 10; // get 1 digit to analyse
        sum = sum + lastDigit; // sum the digits
        workingCC = workingCC / 100; // take every two digits
    }

    // 2nd case
    workingCC = creditCardNumber / 10; // skip the last digit

    while (workingCC > 0) // while loop
    {
        int lastDigit = workingCC % 10; // get 1 digit to analyse
        int timesTwo = lastDigit * 2; // multiply by 2

        sum = sum + (timesTwo % 10) + (timesTwo / 10); // sum the digits add those products’ digits (i.e., not the products themselves)
        workingCC = workingCC / 100; // take every two digits
    }

    // length of the number / digit count
    workingCC = creditCardNumber;
    while (workingCC != 0)
    {
        workingCC = workingCC / 10;
        count++;
    }

    // divisor
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = creditCardNumber / divisor; // Declare variable
    int firstTwoDigits = creditCardNumber / (divisor / 10); // Declare variable

    // final check brand card
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16)) //VISA
        {
            strcpy(result, "VISA");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15) //AMEX
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && count == 16) //MASTERCARD
        {
            strcpy(result, "MASTERCARD");
        }
        else
        {
            strcpy(result, "INVALID"); //INVALID
        }
    }
    else
    {
        strcpy(result, "INVALID"); //INVALID
    }

    printf("%s\n", result); //ANSWER
}

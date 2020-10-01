//********************************************************************************************************************
// Create a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.
// If the user fails to provide a non-negative value, the program re-prompt the user for a valid amount again and again until the user complies.
//********************************************************************************************************************

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar; // Declares dollar variable
    
    do // Do-While loop
    {
        dollar = get_float("Enter your change: "); //take user input
    }
    while (dollar <= 0); // Condition re-prompting the user again and again until non-negative value
    
    int cents = round(dollar * 100); // Declares cents variable
    int coins = 0; // Declares coins variable
    
    //quarters (25¢)
    while (cents >= 25)
    {
        cents -= 25; // cents = cents - 25
        coins++;     // coins = coins + 1
    }
    //dimes (10¢)
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    //nickels (5¢)
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    //pennies (1¢)
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    
    printf("You will need at least %i coins\n", coins);
}

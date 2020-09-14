#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    do
    {
        dollar = get_float("Enter your change: ");
    }
    while (dollar <= 0);
    
    int cents = round(dollar * 100);
    int coins = 0;
    //quarters
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    //dimes
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    //nickels
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    //pennies
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    
    printf("You will need at least %i coins\n", coins);
}

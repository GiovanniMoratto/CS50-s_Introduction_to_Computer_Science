//********************************************************************************************************************
// Create a Nintendo’s Super Mario Brothers right-aligned pyramid of blocks using hashes (#) for bricks.
//********************************************************************************************************************
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // Declares Height variable
    
    do // Do-While loop
    {
        n = get_int("Height: "); //take user input
    }
    while (n < 1 || n > 8); // Condition re-prompting the user again and again until positive integer between 1 and 8
    
    for (int i = 0; i < n; i++) // Loop for lines
    {
        for (int j = 0; j < n; j++) // Loop for print
        {
            if (i + j < n - 1) //blanckspaces
            {
                printf(" ");
            }
            else //hashes #
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // Declares Height variable
    
    do // Do-While loop
    {
        n = get_int("Height: "); // take user input
    }
    while (n < 1 || n > 8); // Condition re-prompting the user again and again until positive integer between 1 and 8
    
    for (int i = 0; i < n; i++) // Loop for lines
    {
        for (int j = 0; j < n - i - 1; j++) // blanckspaces to align the first column
        {
            printf(" ");
        }
        
        for (int column1 = 0; column1 <= i; column1++) //first column
        {
            printf("#");
        }
        
        printf("  "); //middle
       
        for (int column2 = 0; column2 <= i; column2++) //secound column
        {
            printf("#");
        }
        
        printf("\n"); //new line
    }
}

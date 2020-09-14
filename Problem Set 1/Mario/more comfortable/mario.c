#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);
    //new line
    for (int y = 0; y < x; y++)
    {
        //blanckspaces
        for (int k = 0; k < x - y - 1; k++)
        {
            printf(" ");
        }
        //first column
        for (int z = 0; z <= y; z++)
        {
            printf("#");
        }
        printf("  ");
        //secound column
        for (int z2 = 0; z2 <= y; z2++)
        {
            printf("#");
        }
        printf("\n");
    }
}

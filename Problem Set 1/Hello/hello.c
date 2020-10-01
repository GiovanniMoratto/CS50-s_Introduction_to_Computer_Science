//********************************************************************************************************************
// Create a "Hello World" program taking the user input to get the user's name
//********************************************************************************************************************

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}

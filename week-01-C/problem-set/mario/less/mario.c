#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare height variable
    int height;

    // Get user input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Outer loop / Switch to next line of the pyramid after printing the spaces and blocks:
    for (int i = 0; i < height; i++)
    {

        // Print the spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print the blocks
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Go to the next line
        printf("\n");
    }
}

// Prints chars' ASCII codes
#include <cs50.h>
#include <stdio.h>


int main(void)
{
    string s = "HI!";

    // Print the ASCII codes of each character in the string, including the null terminator
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}

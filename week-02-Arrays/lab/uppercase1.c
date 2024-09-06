// Converts a lowercase string to uppercase

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string s = get_string("Before: ");
    printf("After:  ");

    // Iterate over each character in the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Check if the character is lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // Convert lowercase to uppercase by subtracting 32 from the ASCII value
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

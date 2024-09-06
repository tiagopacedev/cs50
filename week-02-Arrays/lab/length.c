// Calculate string length without strlen

#include <cs50.h>
#include <stdio.h>

// Function prototype
int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");

    // Calculate string length
    int length = string_length(name);

    // Print length
    printf("%i\n", length);
}

// Calculate length of string
int string_length(string s)
{
    int n = 0;

    // Iterate until null terminator
    while (s[n] != '\0')
    {
        n++;
    }

    return n;
}

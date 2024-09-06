#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string arg);
char rotate(char chr, int key);

int main(int argc, string argv[])
{
    // Check if there are exactly 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the argument is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Get user text
    string plaintext = get_string("plaintext: ");

    // Encrypt and print the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Function to check if a string contains only digits
bool only_digits(string arg)
{
    for (int i = 0, len = strlen(arg); i < len; i++)
    {
        if (!isdigit(arg[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by a given key
char rotate(char chr, int key)
{
    if (isalpha(chr))
    {j
        if (isupper(chr))
        {
            return (chr - 'A' + key) % 26 + 'A';
        }
        else if (islower(chr))
        {
            return (chr - 'a' + key) % 26 + 'a';
        }
    }
    return chr;
}

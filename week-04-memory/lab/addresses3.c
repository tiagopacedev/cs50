// Prints a string's address as well as the addresses of its characters

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);      // Pointer to the first character of the string (e.g., 0x5767b814d004)
    printf("%p\n", &s[0]);  // Address of the first character (e.g., 0x5767b814d004)
    printf("%p\n", &s[1]);  // Address of the second character
    printf("%p\n", &s[2]);  // Address of the third character
    printf("%p\n", &s[3]);  // Address of the null terminator
}

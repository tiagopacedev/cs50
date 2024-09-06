// Stores and prints an integer via its address

#include <stdio.h>

int main(void)
{
    int n = 50;  // & Provides the address of something stored in memory.
    int *p = &n; // * Instructs the compiler to go to a location in memory.

    printf("%i\n", *p);
}

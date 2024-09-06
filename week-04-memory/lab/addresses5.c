// Prints substrings via pointer arithmetic

#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);      // s = s[0]
    printf("%s\n", s + 1);  // s + 1 = s[1]
    printf("%s\n", s + 2);  // s + 2 = s[2]
}

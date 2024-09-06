#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Contains garbage values since no values are initialized
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}

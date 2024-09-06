#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 45, 50, 80, 100};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n )
        {
            printf("found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

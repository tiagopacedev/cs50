#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;

    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    int coins = 0;

    // Calculate the number of coins
    coins += change / 25; // Quarters
    change %= 25;

    coins += change / 10; // Dimes
    change %= 10;

    coins += change / 5; // Nickels
    change %= 5;

    coins += change; // Pennies

    printf("%i\n", coins);
}

//Return number of coins needed to give a change to user

#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Create new data structure that consists of coins and rest
struct coinsRest
{
    int coin, rest;
};

// Give a new data structure name
typedef struct coinsRest leftCoins;

float owed(void);
leftCoins coin_number(float n);

//Main function
int main()
{
    leftCoins result;

    float change = owed();

    result = coin_number(change);
    printf("%d\n", result.coin);

    return 0;
}

//Promt user to tell change owed
float owed(void)
{
    float n;
    do
    {
        n = get_float("Change owed:");
    }
    while (n < 0.00);
    return n;
}

// Returns number of coins needed to give change owed
leftCoins coin_number(float n)
{
    leftCoins c;
    int coins = 0;
    int rests = (int)round(n * 100);
    {
        // Check if rest of owed is larger than 0.25 cents
        while (rests >= 25)
        {
            coins++;
            rests = rests - 25;
        }
        // Check if rest of owed is larger than 0.10 cents
        while (rests >= 10)
        {
            coins++;
            rests = rests - 10;
        }
        // Check if rest of owed is larger than 0.05 cents
        while (rests >= 5)
        {
            coins++;
            rests = rests - 5;
        }
        // Check if ther any rest of owed
        while (rests < 5 && rests > 0)
        {
            coins++;
            rests = rests - 1;
        }
    }
    c.coin = coins;
    c.rest = rests;
    return c;
}

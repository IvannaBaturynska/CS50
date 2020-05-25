// Determine if a credit card number is (syntactically) valid

#include <stdio.h>
#include <cs50.h>
#include <math.h>

//American Express numbers start with 34 or 37; uses 15-digit numbers
//MasterCard numbers start with 51, 52, 53, 54, or 55; uses 16-digit numbers
//Visa numbers start with 4; 13- and 16-digit numbers

long card_number(void);
int digits(long n);
int sums(long n);

int main(void)
{
    long card = card_number(); //get card number
    int digit = digits(card); // get length of card number
    int last_digit = sums(card); // get last digit of sum of card numbers


    if (last_digit == 0) // if last digit of sum of card numbers, find correct type of a card
    {
        // card / 10000000000000 takes first two digits of card number with length 15
        if (digit == 15 && (card / 10000000000000 == 34 || card / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        // card / 100000000000 takes first two digits of card number with length 13
        else if (digit == 13 && card / 1000000000000 == 4)
        {
            printf("VISA\n");
        }

        else if (digit == 16)
        {
            int two_digit = card / 100000000000000; // card / 100000000000000 takes first two digits of card number
            int one_digit = card / 1000000000000000; // card / 1000000000000000 takes first digit of card number with length 16
            if (two_digit == 51 || two_digit == 52 || two_digit == 53 || two_digit == 54 || two_digit == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (one_digit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}


//Promt user for card number
long card_number(void)
{
    long card;
    do
    {
        card = get_long("Number:");
    }
    while (card < 1);
    return card;
}

// Returns a length of a card number
int digits(long n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;     // n = n/10
        count++;
    }
    return count;
}

// Calculates a sum of digits in a card number using Luhn’s Algorithm
int sums(long n)
{
    int count = 0;
    int sumA = 0;
    int sumB = 0;
    int k = 0;

    while (n != 0) // n is a card number
    {
        int check = n % 10; //take a last digit from the current card number
        n /= 10;     // n = n/10 updates a card number by separating one last digit from the last card number until it is empty
        count++; // counts the position of a digit from card number

        if (count % 2 == 0) //if position is odd, we conduct calculation by using Luhn’s Algorithm
        {
            if (check * 2 < 9) // check if a digit*2 consists of one digit
            {
                sumA = sumA + check * 2;
            }
            else // if a digit*2 consists of two digits
            {
                k = check * 2;
                while (k != 0)
                {
                    int k1 = k % 10; //separate digits
                    k /= 10;
                    sumA = sumA + k1; //calculate sum for each digit individually
                }
            }
        }
        else
        {
            sumB = sumB + check;
        }
    }
    int s = (sumA + sumB) % 10; // takes the last digit of a sum
    if (s == 0) // if last digit is 0, then the card is valid
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
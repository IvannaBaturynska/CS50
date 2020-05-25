//Right-aligned pyramid
#include <cs50.h>
#include <stdio.h>

int height(void);
void pyramid(int n);


int main(void)
{
    int n = height();
    pyramid(n);
}

//Promt user for possitive integer larger than 1 and smaller than 8
int height(void)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    return n;
}

//Composing two-sided pyramid
void pyramid(int n)
{
    //composing a pyramid row by row of height n
    for (int i = 0; i < n; i++)
    {
        //composing two sides in a row for pyramid of height n, where length of raw is two height plus space in between
        for (int j = 0; j < n * 2 + 2; j++)
        {
            //check how many spaces before hashes to add to left-sided pyramid
            if (j < n - (i + 1))
            {
                printf(" ");
            }
            // add a space column between two right and left pyramid
            else if (j == n || j == n + 1)
            {
                printf(" ");
            }
            //check how many space after hashes to add to right-sided pyramid
            else if (j > n + i + 2)
            {}
            //fill left over space with hashes
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

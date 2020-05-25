//Right-aligned pyramide

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

//Composing right-aligned pyramide
void pyramid(int n)
{
    //composing a pyramide row by row of height n
    for (int i = 0; i < n; i++)
    {
        //composing a row for pyramide of height n
        for (int j = 0; j < n; j++)
        {
            //check how many spaces before hashes to add
            if (j < n - (i + 1))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

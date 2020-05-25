//Implement a program that encrypts messages using Caesar’s cipher

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string cipher_encrypt(int key, string text);


int main(int argc, char *argv[])
{
    if (argc != 2) // check if user enters a value in command line
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if entered value is digital
    string isDigit;
    isDigit = argv[1];

    for (int i = 0; isDigit[i] != '\0'; i++)
    {
        if (!isdigit(isDigit[i])) // if entered value is not digital, print the error
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int cipher_key = atoi(argv[1]); // from string to digital

    if (cipher_key == 0) // if digital is 0, print error
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext:"); // promts user for plain text and cipher key
        string ciphertext = cipher_encrypt(cipher_key, plaintext); //returns cipher text with respect to the cipher key
        printf("ciphertext: %s", ciphertext);
        printf("\n");
        return 0;
    }
}

// ci = (pi + k) % 26
string cipher_encrypt(int key, string text)
{
    double character;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((int)text[i] >= 65 && (int)text[i] <= 90) // check for characters with alphabet from A to Z
        {
            character = (((int)text[i] - 65) + key) % 26; //// ci = (pi + k) % 26
            text[i] = character + 65;
        }
        else if ((int)text[i] >= 97 && (int)text[i] <= 122) // check for characters with alphabet from a to z
        {
            character = (((int)text[i] - 97) + key) % 26; // // ci = (pi + k) % 26
            text[i] = character + 97;
        }
        else
        {
            character = (int)text[i];
            text[i] = character;
        }
    }

    return (string)text;
}


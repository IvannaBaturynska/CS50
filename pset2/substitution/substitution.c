/* Encrypt a message by replacing every letter with another letter
provided by user in command line*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int lengthArgv(string originKey);
string toUpper(string origKey);
bool isDuplicate(string Key);
int *key(string originalKey);
string cipher_encrypt(int *key, string text);

int main(int argc, char *argv[])
{
    if (argc != 2) // check if user enters a value in command line
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string lenArgv = argv[1];
    for (int i = 0; lenArgv[i] != '\0'; i++)
    {
        if (!isalpha(lenArgv[i])) // if entered value is not alphabet, print the error
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (lengthArgv(lenArgv) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string originKey = argv[1];

    if (isDuplicate(originKey) == true)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");

        int *cipher_key = key(originKey); // return transformed original key as digital key for each character
        string ciphertext = cipher_encrypt(cipher_key, plaintext); //returns cipher text with respect to the cipher key
        printf("ciphertext: %s", ciphertext);

        free(cipher_key);
        printf("\n");
        return 0;

    }
}




string toUpper(string origKey)
{
    for (int i = 0; origKey[i] != '\0'; i++)
    {
        origKey[i] = toupper(origKey[i]);
    }
    return origKey;
}

// check for duplicates
bool isDuplicate(string Key)
{
    string UpperKey = toUpper(Key);
    bool flag = false;

    int local [26];

    for (int i = 0; i < 26; i++)
    {
        local[i] = UpperKey[i] - 65; // transform original key letter into upper letters
    }

    for (int i = 0; i < 26; i++)
    {
        if (local[abs(local[i])] >= 0) //check if we have visited this location, if positive than no
        {
            local[abs(local[i])] = -local[abs(local[i])];
        }
        else // we have visited location because internal value is negative
        {
            flag = true;
        }
    }
    return flag;

}


// Calculate length of entered key via command line
int lengthArgv(string originKey)
{
    int count = 0;
    for (int i = 0; originKey[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}



// returns transformed original key as digital key for each character
int *key(string originalKey)
{
    int length = lengthArgv(originalKey);

    int *cipherKey; // This pointer will hold the base address of the block created
    cipherKey = (int *) calloc(length, sizeof(int)); // Dynamically allocate memory using calloc()

    for (int i = 0; originalKey[i] != '\0'; i++)
    {
        cipherKey[i] = (int) originalKey[i];

        if (cipherKey[i] >= 65 && cipherKey[i] <= 90) // transformes alphabet key into digital key for A to Z
        {
            cipherKey[i] = cipherKey[i] - (65 + i);
        }
        else if (cipherKey[i] >= 97 && cipherKey[i] <= 122) // transformes alphabet key into digital key for a to z
        {
            cipherKey[i] = cipherKey[i] - (97 + i);
        }
    }
    return cipherKey;
}




// ci = (pi + k) % 26
string cipher_encrypt(int *key, string text)
{
    double character;

    for (int i = 0; text[i] != '\0'; i++)
    {
        int location;

        if ((int)text[i] >= 65 && (int)text[i] <= 90) // check for characters with alphabet from A to Z
        {
            location = (int)text[i] - 65;

            // ci = (pi + k) % 26 with respect to the alhabet and new key
            character = (location + key[location]) % 26;
            text[i] = character + 65;
        }
        else if ((int)text[i] >= 97 && (int)text[i] <= 122) // check for characters with alphabet from a to z
        {
            location = (int)text[i] - 97;

            // ci = (pi + k) % 26 with respect to the alhabet and new key
            character = (location + key[location]) % 26;
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
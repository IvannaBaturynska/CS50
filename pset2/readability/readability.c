/* Evaluate U.S. readability grade computed
by the Coleman-Liau formula */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_letters(string text); //count letters in a text
int count_words(string text); // count words in a text
int count_sentences(string text); // count sentences in a text

// calculates average of total (value1 =) {letters, senteces} per 100 (value2 =) words
float average(int value1, int value2, int per_number_of);

int readability(string text); // evaluate index for readability of the text

int main(void)
{
    string text = get_string("Test: "); //Promts text from user

    int grade = readability(text); //gets the readability index

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
    return 0;
}

/* count the number of:
- letters,
- words, and
- sentences in the text */

//function counts the number of letters
int count_letters(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 65 && text[i] <= 90) // count the number of characters from 'a' to 'z'
        {
            count ++;
        }
        else if (text[i] >= 97 && text[i] <= 122) // count the number of characters from 'A' to 'Z'
        {
            count++;
        }
    }
    return count;
}

//function counts the number of words
int count_words(string text)
{
    int count = 0;
    int space = 32;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text [i] == space) //count the number of spaces in the text
        {
            count ++;
        }
    }

    return count + 1;

}

//function counts the number of senteces
int count_sentences(string text)
{
    int count = 0;
    int punktum = 46;
    int question = 63;
    int exclamait = 33;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text [i] == punktum) //count the number of characters equal to '.' in the text
        {
            count ++;
        }
        else if (text [i] == question) //count the number of characters equal to '?' in the text
        {
            count ++;
        }
        else if (text [i] == exclamait) //count the number of characters equal to '!' in the text
        {
            count ++;
        }
    }

    return count;
}

// compute average number of value 1 per_number_of value2
float average(int value1, int value2, int per_number_of)
{
    return ((float) value1 * per_number_of) / value2;

}

//compute the readability index by the Coleman-Liau formula
int readability(string text)
{

    int letters = count_letters(text); // gets number of letters from function count_letters()
    int words = count_words(text); // gets number of words from function count_words()
    int sentences = count_sentences(text); // gets number of sentences from function count_sentences()

    const float const1 = 0.0588; //first constant from the Coleman-Liau formula
    const float const2 = 0.296; //second constant from the Coleman-Liau formula
    const float const3 = 15.8; //third constant from the Coleman-Liau formula

    float L = average(letters, words, 100); //compute average number of letter per 100 words
    float S = average(sentences, words, 100); //compute average number of sentences per 100 words

    float index =  const1 * L - const2  * S - const3; // compute readability index

    return round(index);

}

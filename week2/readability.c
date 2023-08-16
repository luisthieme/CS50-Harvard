#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[200];
    char punkt[1] = ".";
    char ausrufezeichen[1] = "!";
    char fragezeichen[1] = "?";
    float letters = 0, sentences = 0, words = 1;

    printf("Enter Text: ");
    scanf("%[^\n]%*c", text); 

    int lenght = strlen(text);

    for(int counter = 0; counter < lenght; counter++)
    {
        char current_char = text[counter];

        switch(current_char)
        {
            case ' ':
                words++;
                break;
            case '.':
                sentences++;
                break;
            case '!':
                sentences++;
                break;
            case '?':
                sentences++;
                break;
            case '\'':
                break;
            case '\"':
                break;
            default:
                letters++;
        }
    }

    printf("words: %f letters: %f sentences: %f\n", words, letters, sentences);

    double letters_per_100_words = letters / (words / 100);
    double sentences_per_100_words = sentences / (words / 100);

    printf("%f %f\n", letters_per_100_words, sentences_per_100_words);

    int index = round(0.0588 * letters_per_100_words - 0.296 * sentences_per_100_words - 15.8);
    
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}


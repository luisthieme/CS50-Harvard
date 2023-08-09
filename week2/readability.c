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
    scanf("%[^\n]%*c", text); // in c kann man mit der scanf funktion alleine nur einen string input annehmen bis zum ersten leerzeichen. um das zu umgehen muss man statt %s als placeholder %[^\n]%*c benutzen.

    int lenght = strlen(text);

    for(int i = 0; i < lenght; i++)
    {
        char x = text[i];

        switch(x)
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

    double l = letters / (words / 100);
    double s = sentences / (words / 100);

    printf("%f %f\n", l, s);

    int index = round(0.0588 * l - 0.296 * s - 15.8);
    
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


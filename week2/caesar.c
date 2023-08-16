#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2)
    {
        printf("Please input exactly one key!\n");
        return 1;
    }

    int key = atoi(argv[1]);

    if(key == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    while(key > 26)
    {
        key -= 26;
    }

    int ascii;
    char text[50];

    printf("plaintext:  ");
    scanf("%[^\n]%*c", text);
    printf("ciphertext: ");

    int lenght = strlen(text);

    for(int counter = 0; counter < lenght; counter++)
    {
        if((text[counter] != (' ' | '.' | '?' | '!' | '\'')) && (text[counter] > 96) && (text[counter] < 123))
        {
            ascii = text[counter];
            ascii += key;
            if(ascii > 122)
            {
                ascii -= 26;
            }

            printf("%c", ascii);
        }
        else if((text[counter] != (' ' | '.' | '?' | '!' | '\'')) && (text[counter] > 64) && (text[counter] < 91))
        {
            ascii = text[counter];
            ascii += key;
            if(ascii > 90)
            {
                ascii -= 26;
            }

            printf("%c", ascii);
        }
        else
        {
            printf("%c", text[counter]);
        }
    }

    printf("\n");

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

    int key = atoi(argv[1]);
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

    for(int i = 0; i < lenght; i++)
    {
        if((text[i] != (' ' | '.' | '?' | '!' | '\'')) && (text[i] > 96) && (text[i] < 123))
        {
            ascii = text[i];
            ascii += key;
            if(ascii > 122)
            {
                ascii -= 26;
            }
            printf("%c", ascii);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");

    // noch für großbcuhstaben implementieren

}
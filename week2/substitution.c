#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    if(argc < 2 || argc > 2)
    {
        printf("Please input exactly one key!\n");
        return 1;
    }

    char* input = argv[1];
    char key[200];

    for(int i = 0; i < strlen(input); i++)
    {
        int input_i = input[i];
        if(input_i < 91 || input_i < 64)
        {
            input_i += 32;
            key[i] = input_i;

        }
        else
        {
            key[i] = input_i;
        }
    }

    if(strlen(key)!= 26)
    {
        printf("please enter excactly 26 letters!\n");
        return 1;
    }
    
    for(int i = 0; i < strlen(key); i++)
    {

    }


    int duplicate;
    for (int i = 0; i < strlen(key) - 1; i++) 
    {
        for (int j = i + 1; j < strlen(key); j++) 
        {
            if (key[i] == key[j]) 
            {
                
                duplicate = 1;
            }
        }
    }
    if(duplicate == 1)
    {
        printf("please only enter unique letters!\n");
        return 1;
    }

    int nonletters;

    for(int i = 0; i < strlen(key); i++)
    {
        if(key[i] < 33 || key[i] > 90 || (key[i] > 58 && key[i] < 65))
        {
            nonletters = 1;
        }
    }

    if(nonletters == 1)
    {
        printf("please enter only alphabetic characters!\n");
        return 1;
    }

    char text[50];

    printf("plaintext:  ");
    scanf("%[^\n]%*c", text);

    char cipher[50];

    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] > 96 && text[i] < 123)
        {
            int temp = text[i];
            temp -= 97;
            cipher[i] = key[temp];
        }
        else if(text[i] > 64 && text[i] < 91)
        {
            int temp = text[i];
            temp -= 65;
            int x = key[temp];
            x -= 32;
            cipher[i] = x;
        }
        else
        {
            cipher[i] = text[i];
        }
    }
    
    printf("ciphertext: ");
    printf("%s\n", cipher);
}

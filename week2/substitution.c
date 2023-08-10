#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) 
{
    if(argc < 2 || argc > 2)
    {
        printf("Please input exactly one key!\n");
        return 1;
    }

    char* input_as_ascii_code = argv[1];
    char conversion_key[200];

    for(int char_slot = 0; char_slot < strlen(input_as_ascii_code); char_slot++)
    {
        int input_i = input_as_ascii_code[char_slot];
        bool isUppercase = input_i < 91 || input_i > 64;
        if(isUppercase)
        {
            input_i += 32;
            conversion_key[char_slot] = input_i;
        }
        else
        {
            conversion_key[char_slot] = input_i;
        }
    }

    if(strlen(conversion_key)!= 26)
    {
        printf("please enter excactly 26 letters!\n");
        return 1;
    }

    int duplicate;
    for (int i = 0; i < strlen(conversion_key) - 1; i++) 
    {
        for (int j = i + 1; j < strlen(conversion_key); j++) 
        {
            if (conversion_key[i] == conversion_key[j]) 
            { 
                duplicate = true;
            }
        }
    }

    if(duplicate)
    {
        printf("please only enter unique letters!\n");
        return 1;
    }

    int nonletters;

    for(int char_in_key = 0; char_in_key < strlen(conversion_key); char_in_key++)
    {
        if(conversion_key[char_in_key] < 33 || conversion_key[char_in_key] > 90 || (conversion_key[char_in_key] > 58 && conversion_key[char_in_key] < 65))
        {
            nonletters = true;
        }
    }

    if(nonletters)
    {
        printf("please enter only alphabetic characters!\n");

        return 1;
    }

    char text[50];

    printf("plaintext:  ");
    scanf("%[^\n]%*c", text);

    char ciphertext[50];

    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] > 96 && text[i] < 123)
        {
            int temp = text[i];
            temp -= 97;
            ciphertext[i] = conversion_key[temp];
        }
        else if(text[i] > 64 && text[i] < 91)
        {
            int temp = text[i];
            temp -= 65;
            int x = conversion_key[temp];
            x -= 32;
            ciphertext[i] = x;
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    
    printf("ciphertext: ");
    printf("%s\n", ciphertext);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Please input exactly one key!\n");

        return 1;
    }

    char *input_as_ascii_code = argv[1];
    char conversion_key[200];

    for (int char_slot = 0; char_slot < strlen(input_as_ascii_code); char_slot++)
    {
        int input_as_int = input_as_ascii_code[char_slot];
        bool isUppercase = input_as_int < 91 || input_as_int > 64;
        if (isUppercase)
        {
            input_as_int += 32;
            conversion_key[char_slot] = input_as_int;
        }
        else
        {
            conversion_key[char_slot] = input_as_int;
        }
    }

    if (strlen(conversion_key) != 26)
    {
        printf("please enter excactly 26 letters!\n");

        return 1;
    }

    bool duplicate;
    for (int counter = 0; counter < strlen(conversion_key) - 1; counter++)
    {
        for (int inner_counter = counter + 1; inner_counter < strlen(conversion_key); inner_counter++)
        {
            if (conversion_key[counter] == conversion_key[inner_counter])
                duplicate = true;
        }
    }

    if (duplicate)
    {
        printf("please only enter unique letters!\n");

        return 1;
    }

    bool nonletters;

    for (int char_in_key = 0; char_in_key < strlen(conversion_key); char_in_key++)
    {
        bool nonletters = conversion_key[char_in_key] < 33 || conversion_key[char_in_key] > 90 || (conversion_key[char_in_key] > 58 && conversion_key[char_in_key] < 65);

        if (nonletters)
        {
            printf("please enter only alphabetic characters!\n");

            return 1;
        }
    }

    char text[50];

    printf("plaintext:  ");
    scanf("%[^\n]%*c", text);

    char ciphertext[50];

    for (int counter = 0; counter < strlen(text); counter++)
    {
        if (text[counter] > 96 && text[counter] < 123)
        {
            int temp_value = text[counter];
            temp_value -= 97;
            ciphertext[counter] = conversion_key[temp_value];
        }
        else if (text[counter] > 64 && text[counter] < 91)
        {
            int temp_value = text[counter];
            temp_value -= 65;
            int current_char = conversion_key[temp_value];
            current_char -= 32;
            ciphertext[counter] = current_char;
        }
        else
        {
            ciphertext[counter] = text[counter];
        }
    }

    printf("ciphertext: ");
    printf("%s\n", ciphertext);
}

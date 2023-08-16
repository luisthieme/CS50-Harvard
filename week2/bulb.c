#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[50];
    char output[9];

    printf("Enter message: ");
    scanf("%[^\n]%*c", text);

    int lenght = strlen(text);

    for(int counter = 0; counter < lenght; counter++)
    {
        for (int inner_counter = 7; inner_counter >= 0; --inner_counter)
        {
            putchar((text[counter] & (1 << inner_counter)) ? '1' : '0' );
        }

        putchar('\n');
    }
}

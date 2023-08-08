#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[50];
    char output[9];

    printf("Enter message: ");
    scanf("%[^\n]%*c", text);

    int lenght = strlen(text);

    for(int i = 0; i < lenght; i++)
    {
        for (int j = 7; j >= 0; --j)
        {
            putchar((text[i] & (1 << j)) ? '1' : '0' );
        }
        putchar('\n');
    }
}

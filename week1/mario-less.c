#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    int n;
    char input[50];
    int counter = 1;
    do
    {
        printf("size: ");
        scanf("%s", input);
        n = atoi(input);
    } while (!(n > 0 && n < 9));
    
    
    int spaces = n;

    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < spaces; k++)
        {
            printf(" ");
        }

        for(int j = 0; j < counter; j++)
        {
            printf("#");
        }

        printf("  ");

        for(int j = 0; j < counter; j++)
        {
            printf("#");
        }

        printf("\n");
        counter++;
        spaces--;
    }
    
    printf("\n");

}
#include <stdio.h>

int main(void)
{
    int n;
    int counter = 1;
    do
    {
        printf("size: ");
        scanf("%d", &n);
    } while (!(n > 1 && n < 8));
    
    
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
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    int input_as_number;
    char input[50];
    int counter = 1;

    do
    {
        printf("size: ");
        scanf("%s", input);
        input_as_number = atoi(input);
    } while (!(input_as_number > 0 && input_as_number < 9));
    
    int spaces = input_as_number;

    for(int counter = 0; counter < input_as_number; counter++)
    {
        for(int inner_counter = 0; inner_counter < spaces; inner_counter++)
        {
            printf(" ");
        }

        for(int inner_counter = 0; inner_counter < counter; inner_counter++)
        {
            printf("#");
        }

        printf("  ");

        for(int inner_counter = 0; inner_counter < counter; inner_counter++)
        {
            printf("#");
        }

        printf("\n");
        counter++;
        spaces--;
    }
    
    printf("\n");
}

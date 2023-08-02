#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    char input[50];
    int cardnumber;

    do
    {
        printf("Enter Number: ");
        scanf("%s", &input);
        cardnumber = atoi(input);
    } while (cardnumber == 0);
    
    
    
    



}
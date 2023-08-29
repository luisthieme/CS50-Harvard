#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[50];
    int cardnumber;
    char input_as_char;
    int type1_numbers = 0;
    int type2_numbers = 0;
    int temp = 0, remainder = 0, sum = 0, first_digit = 0, sec_digit = 0;
    char first_digit_as_char, sec_digit_as_char;

    do
    {
        printf("Enter Number: ");
        scanf("%s", input);
        cardnumber = atoi(input);
        printf("%d", cardnumber);
    } while (cardnumber == 0);

    for(int i = 0; i < strlen(input); i++)
    {
        int temp = (strlen(input) - 1 - i);
        input_as_char = input[temp];
        int current_num = atoi(&input_as_char);
        if(i % 2 == 0)
        {
            type1_numbers += current_num;
        }
        else
        {
            temp = current_num * 2;
            while(temp != 0)
            {
                remainder = temp % 10;
                sum = sum + remainder;
                temp = temp / 10;
            }

            type2_numbers += sum;
            sum = 0;
        }
    }

    first_digit_as_char = input[0];
    first_digit = atoi(&first_digit_as_char);

    sec_digit_as_char = input[1];
    sec_digit = atoi(&sec_digit_as_char);

    if((type1_numbers + type2_numbers) % 10 != 0)
    {
        printf("INVALID CARD NUMBER\n");
    }   
    else if(sec_digit == 43)
    {  
        printf("AMEX\n");
    }
    else if(sec_digit == 73)
    {
        printf("AMEX\n");
    }
    else if(first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("MASTERCARD\n");
    }
}

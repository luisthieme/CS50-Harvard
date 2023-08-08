#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[50];
    int cardnumber;
    char input_c;
    int type1 = 0;
    int type2 = 0;
    int t = 0, remainder = 0, sum = 0, first_digit = 0, sec_digit = 0;
    char first_digit_s, sec_digit_s;

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
        input_c = input[temp];
        int current_num = atoi(&input_c);
        if(i % 2 == 0)
        {
            type1 += current_num;
        }else
        {
            t = current_num * 2;
            while(t != 0)
            {
                remainder = t % 10;
                sum = sum + remainder;
                t = t / 10;
            }
            type2 += sum;
            sum = 0;
        }
    }

    first_digit_s = input[0];
    first_digit = atoi(&first_digit_s);

    sec_digit_s = input[1];
    sec_digit = atoi(&sec_digit_s);



    if((type1 + type2) % 10 != 0)
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

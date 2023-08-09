#include <stdio.h>

int main(void)
{
    int cents;
    int coin_counter = 0;

    printf("Cents: ");
    scanf("%d", &cents);

    while(cents > 0)
    {
        while(cents > 24)
        {
            cents -= 25;
            coin_counter++;
        }

        while(cents > 9)
        {
            cents -= 10;
            coin_counter++;
        }

        while(cents > 4)
        {
            cents -= 5;
            coin_counter++;
        }

        while(cents > 0)
        {
            cents -= 1;
            coin_counter++;
        }
    }

    printf("%d\n", coin_counter);
}

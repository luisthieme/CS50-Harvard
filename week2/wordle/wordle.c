#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define LISTSIZE 1000
#define EXACT 2
#define CLOSE 1
#define WRONG 0
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("please enter only one number! nothing more nothing less.\n");
        return 1;
    }

    int wordsize = 0;
    wordsize = atoi(argv[1]);

    if (wordsize > 8 || wordsize < 5)
    {
        printf("the wordsize must be between 5-8!\n");
        return 1;
    }

    char wordlist_filename[6];
    sprintf(wordlist_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wordlist_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wordlist_filename);
        return 1;
    }

    char options[LISTSIZE][wordsize + 1];

    for (int counter = 0; counter < LISTSIZE; counter++)
    {
        fscanf(wordlist, "%s", options[counter]);
    }

    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    int guesses = wordsize + 1;
    bool won = false;

    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    for (int counter = 0; counter < guesses; counter++)
    {
        string guess = get_guess(wordsize);
        int status[wordsize];

        for (int counter = 0; counter < wordsize; counter++)
        {
            status[counter] = 0;
        }

        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", counter + 1);
        print_word(guess, wordsize, status);

        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    if (won)
    {
        printf("You won!\n");
    }
    else
    {
        printf("You lost! The word was: %s\n", choice);
    }

    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    do
    {
        guess = get_string("Input a %s -letter word: ", wordsize);
    } while (strlen(guess) != wordsize);

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    for (int counter = 0; counter < wordsize; counter++)
    {
        if (guess[counter] == choice[counter])
        {
            status[counter] = EXACT;
            continue;
        }

        for (int inner_counter = 0; inner_counter < wordsize; inner_counter++)
        {

            if (guess[counter] == choice[inner_counter])
            {
                status[counter] = CLOSE;
            }
        }
    }

    for (int counter = 0; counter < wordsize; counter++)
    {
        score += status[counter];
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    for (int counter = 0; counter < wordsize; counter++)
    {
        if (status[counter] == 2)
        {
            printf(GREEN "%c" RESET, guess[counter]);
        }
        else if (status[counter] == 1)
        {
            printf(YELLOW "%c" RESET, guess[counter]);
        }
        else
        {
            printf(RED "%c" RESET, guess[counter]);
        }
    }

    printf("\n");

    return;
}

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define LISTSIZE 1000
#define EXACT 2
#define CLOSE 1
#define WRONG 0
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("please enter only one number! nothing more nothing less.\n");
        return 1;
    }

    int wordsize = 0;
    wordsize = atoi(argv[1]);
    
    if(wordsize != 5 && wordsize != 6 && wordsize != 7 && wordsize != 8)
    {
        printf("the wordsize must be between 5-8!\n");
        return 1;
    }

    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    int guesses = wordsize + 1;
    bool won = false;

    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    for (int i = 0; i < guesses; i++)
    {
        string guess = get_guess(wordsize);
        int status[wordsize];

        for(int i = 0; i < wordsize; i++)
        {
            status[i] = 0;
        }

        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);
        print_word(guess, wordsize, status);

        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    if(won)
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
        guess = get_string("Your guess: ");
    } while (strlen(guess) != wordsize);

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    for(int i = 0; i < wordsize; i++)
    {  
        for(int j = 0; j < wordsize; j++)
        {
            if(guess[i] == choice[i])
            {
                status[i] = EXACT;
                break;
            }
            if(guess[i] == choice[j])
            {
                status[i] = CLOSE;

            }
        }
    }

    for(int i = 0; i < wordsize; i++)
    {
        score += status[i];
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    for(int i = 0; i < wordsize; i++)
    {
        if(status[i] == 2)
        {
            printf(GREEN"%c"RESET, guess[i]);
        }
        else if(status[i] == 1)
        {
            printf(YELLOW"%c"RESET, guess[i]);
        }
        else
        {
            printf(RED"%c"RESET, guess[i]);
        }
    }

    printf("\n");

    return;
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");

        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);

        return 2;
    }

    for (int counter = 0; counter < candidate_count; counter++)
    {
        candidates[counter].name = argv[counter + 1];
        candidates[counter].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int counter = 0; counter < voter_count; counter++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            counter--;
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(strcmp(name, candidates[counter].name) == 0)
        {
            candidates[counter].votes += 1;

            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;

    for(int counter = 0; counter < candidate_count - 1; counter++)
    {
        if(candidates[counter].votes > max_votes)
        {
            max_votes = candidates[counter].votes;
        }
    }

    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(candidates[counter].votes == max_votes)
        {
            printf("%s\n", candidates[counter].name);
        }
    }
    
    return;
}

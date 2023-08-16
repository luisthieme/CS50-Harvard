#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");

        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);

        return 2;
    }

    for (int counter = 0; counter < candidate_count; counter++)
    {
        candidates[counter].name = argv[counter + 1];
        candidates[counter].votes = 0;
        candidates[counter].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);

        return 3;
    }

    for (int counter = 0; counter < voter_count; counter++)
    {
        for (int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            string name = get_string("Rank %i: ", inner_counter + 1);

            if (!vote(counter, inner_counter, name))
            {
                printf("Invalid vote.\n");

                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();

        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int counter = 0; counter < candidate_count; counter++)
            {
                if (!candidates[counter].eliminated)
                {
                    printf("%s\n", candidates[counter].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int counter = 0; counter < candidate_count; counter++)
        {
            candidates[counter].votes = 0;
        }
    }

    return 0;
}

bool vote(int voter, int rank, string name)
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(strcmp(candidates[counter].name, name) == 0)
        {
            preferences[voter][rank] = counter;

            return true;
        }
    }

    return false;
}

void tabulate(void)
{
    int favourite;

    for(int counter = 0; counter < voter_count; counter++)
    {
        for(int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            favourite = preferences[counter][inner_counter];

            if(!candidates[favourite].eliminated)
            {
                candidates[favourite].votes++;
                break;
            }
        }
    }

    return;
}

bool print_winner(void)
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(candidates[counter].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[counter].name);

            return true;
        }
    }

    return false;
}

int find_min(void)
{
    int min_votes = voter_count;

    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(candidates[counter].votes < min_votes && !candidates[counter].eliminated)
        {
            min_votes = candidates[counter].votes;
        }
    }

    return min_votes;
}

bool is_tie(int min)
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(!candidates[counter].eliminated)
        {
            if(candidates[counter].votes != min && !candidates[counter].eliminated)
            {
                return false;
            }
        }  
    }

    return true;
}

void eliminate(int min)
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(candidates[counter].votes == min)
        {
            candidates[counter].eliminated = true;
        }
    }

    return;
}

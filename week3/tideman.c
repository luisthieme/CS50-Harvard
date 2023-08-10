#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];
int winner;

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(!strcmp(candidates[i], name))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(!(ranks[i] == ranks[j]) && i < j)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int score = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i; j < candidate_count - 1; j++)
        {
            score = preferences[i][j + 1] - preferences[j + 1][i];

            if(score > 0)
            {
                pairs[pair_count].winner = i; 
                pairs[pair_count].loser = j + 1;
                pair_count++;
            }
            else if(score < 0)
            {
                pairs[pair_count].winner = j +1;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int score = 0;
    int scores[pair_count];
    bool sorted = false;
    int swap_counter;

    for(int i = 0; i < pair_count; i++)
    {
        score = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        scores[i] = score;
    }

    while(!sorted)
    {
        swap_counter = 0;

        for(int i = 0; i < pair_count - 1; i++)
        {
            if(scores[i] < scores[i + 1])
            {
                int temp1 = scores[i];
                int temp2 = scores[i + 1];
                scores[i] = temp2;
                scores[i + 1] = temp1;
                swap_counter++;
            }
        } 

        if(swap_counter == 0)
        {
            sorted = true;
        }
    }
    
    for(int i = 0; i < pair_count; i++)
    {
        for(int j = i; j < pair_count; j++)
        {
            if(scores[i] == preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner])
            {
                int temp1 = pairs[j].winner;
                int temp2 = pairs[j].loser;
                
                pairs[j].winner = pairs[i].winner,
                pairs[j].loser = pairs[i].loser;
                
                pairs[i].winner = temp1;
                pairs[i].loser = temp2;
                break;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) //wenn die funktion richtig funktioniert fress ich nen besen
{
    int sources[candidate_count];

    for(int i = 0; i <  candidate_count; i++)
    {
        sources[i] = i;
    }

    for(int i = 0; i < pair_count; i++)
    {
        int is_source = 0;

        for(int j = 0; j < candidate_count; j++)
        {
            if(sources[j] != 99)
            {
                is_source++;
            }
        }

        if(is_source >= 2)
        {
            // pairs[i].loser bekommt ein falsches value es sollte 2 oder 1 bekommen bekommt aber den index 0 
            locked[i][0] = pairs[i].winner;
            locked[i][1] = pairs[i].loser;
            for(int j = 0; j < candidate_count; j++)
            {
                if(sources[j] == pairs[i].loser)
                {
                    sources[j] = 99;
                }
            }
        }
    }

    for(int i = 0; i < candidate_count; i++)
    {
        if(sources[i] != 99)
        {
            winner = sources[i];
        }
        else
        {
            printf("%d\n", sources[i]);
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    printf("%s\n", candidates[winner]);
    return;
}
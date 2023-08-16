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
    
    for (int counter = 0; counter < candidate_count; counter++)
    {
        candidates[counter] = argv[counter + 1];
    }

    // Clear graph of locked in pairs
    for (int counter = 0; counter < candidate_count; counter++)
    {
        for (int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            locked[counter][inner_counter] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int counter = 0; counter < voter_count; counter++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            string name = get_string("Rank %i: ", inner_counter + 1);

            if (!vote(inner_counter, name, ranks))
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
    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(!strcmp(candidates[counter], name))
        {
            ranks[rank] = counter;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int counter = 0; counter < candidate_count; counter++)
    {
        for(int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            if(!(ranks[counter] == ranks[inner_counter]) && counter < inner_counter)
            {
                preferences[ranks[counter]][ranks[inner_counter]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int score = 0;
    for(int counter = 0; counter < candidate_count; counter++)
    {
        for(int inner_counter = counter; inner_counter < candidate_count - 1; inner_counter++)
        {
            score = preferences[counter][inner_counter + 1] - preferences[inner_counter + 1][counter];

            if(score > 0)
            {
                pairs[pair_count].winner = counter; 
                pairs[pair_count].loser = inner_counter + 1;
                pair_count++;
            }
            else if(score < 0)
            {
                pairs[pair_count].winner = inner_counter +1;
                pairs[pair_count].loser = counter;
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

    for(int counter = 0; counter < pair_count; counter++)
    {
        score = preferences[pairs[counter].winner][pairs[counter].loser] - preferences[pairs[counter].loser][pairs[counter].winner];
        scores[counter] = score;
    }

    while(!sorted)
    {
        swap_counter = 0;

        for(int counter = 0; counter < pair_count - 1; counter++)
        {
            if(scores[counter] < scores[counter + 1])
            {
                int temp1 = scores[counter];
                int temp2 = scores[counter + 1];
                scores[counter] = temp2;
                scores[counter + 1] = temp1;
                swap_counter++;
            }
        } 

        if(swap_counter == 0)
        {
            sorted = true;
        }
    }
    
    for(int counter = 0; counter < pair_count; counter++)
    {
        for(int inner_counter = counter; inner_counter < pair_count; inner_counter++)
        {
            if(scores[counter] == preferences[pairs[inner_counter].winner][pairs[inner_counter].loser] - preferences[pairs[inner_counter].loser][pairs[inner_counter].winner])
            {
                int temp1 = pairs[inner_counter].winner;
                int temp2 = pairs[inner_counter].loser;
                
                pairs[inner_counter].winner = pairs[counter].winner,
                pairs[inner_counter].loser = pairs[counter].loser;
                
                pairs[counter].winner = temp1;
                pairs[counter].loser = temp2;
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

    for(int counter = 0; counter <  candidate_count; counter++)
    {
        sources[counter] = counter;
    }

    for(int counter = 0; counter < pair_count; counter++)
    {
        int is_source = 0;

        for(int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
        {
            if(sources[inner_counter] != 99)
            {
                is_source++;
            }
        }

        if(is_source >= 2)
        {
            // pairs[i].loser bekommt ein falsches value es sollte 2 oder 1 bekommen bekommt aber den index 0 
            locked[counter][0] = pairs[counter].winner;
            locked[counter][1] = pairs[counter].loser;
            for(int inner_counter = 0; inner_counter < candidate_count; inner_counter++)
            {
                if(sources[inner_counter] == pairs[counter].loser)
                {
                    sources[inner_counter] = 99;
                }
            }
        }
    }

    for(int counter = 0; counter < candidate_count; counter++)
    {
        if(sources[counter] != 99)
        {
            winner = sources[counter];
        }
        else
        {
            printf("%d\n", sources[counter]);
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

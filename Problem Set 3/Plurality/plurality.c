#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage // check if have less than 2 arguments
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates //limite de 9 candidatos
    candidate_count = argc - 1; // number of arguments -1 (initial command)
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // Sort candidates according to the command line // argv[i + 1] because argv[0] = program name
        candidates[i].votes = 0; // reset initial votes
    }

    int voter_count = get_int("Number of voters: "); // ask and declares the number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // ask for vote

        // Check for invalid vote
        if (!vote(name)) // Check for invalid votes, store the vote and rate the candidates
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

int get_index(string name) //Identify the index number of string name
{
    for (int i = 0; i < candidate_count; i++) // Loop using number of candidates
    {
        if (strcmp(name, candidates[i].name) == 0) // Identify the equality betwen 'name' and 'candidates[i].name'.
        {
            return i; // Get the index number
        }
    }
    return -1;
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    int candidate_index = get_index(name); // Get the index number

    if (candidate_index != -1) // If the index is different from -1
    {
        candidates[candidate_index].votes++; // candidates[i].votes = candidates[candidate_index].votes // adds 1 to the candidate found
        return true;
    }
    return false;
}

int get_max(void)
{
    int max_votes = candidates[0].votes; // Assimilates the number of votes of candidate [0] to max_votes
    for (int i = 1; i < candidate_count; i++) // Loop using number of candidates
    {
        if (candidates[i].votes > max_votes) // Compare the votes of the current candidate with the max_votes 
        {
            max_votes = candidates[i].votes; // if the current candidate is bigger than max_votes, than assimilates.
        }
    }
    return max_votes;  // Get the max_votes
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_votes = get_max(); // Assimilate max_votes
    for (int i = 0; i < candidate_count; i++) // Loop using number of candidates
    {
        if (candidates[i].votes == max_votes) //if the number of votes for the current candidate is equal to max, then ..
        {
            printf("%s\n", candidates[i].name); // Prints the winner (or winners) of the election
        }
    }
    return;
}

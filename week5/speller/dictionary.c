// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Counter for words in the dictionary
int wordCounter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashPosition = hash(word);
    node *cursor = table[hashPosition];

    if(strcasecmp(cursor->word, word) == 0)
    {
        return true;
    }

    while(cursor->next != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;

            if(strcasecmp(cursor->word, word) == 0)
            { 
                return true;
            }
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hashValue = 0;

    int firstLetter = toupper(word[0]) - 'A';
    int secoundLetter = toupper(word[1]) - 'A';
    hashValue = firstLetter + (firstLetter * 25) + secoundLetter;

    printf("%d", hashValue);
    return hashValue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    char inputWord[LENGTH + 1];

    if(file == NULL)
    {
        return false;
    }
    while(fscanf(file, "%s", inputWord) == 1)
    {
        node *currentNode = malloc(sizeof(node));
        wordCounter++;

        strcpy(currentNode->word, inputWord);
        currentNode->next = NULL;

        int hashPosition = hash(currentNode->word);

        if(table[hashPosition] != NULL)
        {
            currentNode->next = table[hashPosition];
            table[hashPosition] = currentNode;
        }
        else
        {
            table[hashPosition] = currentNode;
        }
         
    }
    
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int listInTable = 0; listInTable < N - 1; listInTable++)
    {
        node *cursor = table[listInTable];
        node *temp = table[listInTable];

        while(cursor->next != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        free(cursor);
    }

    return true;
}

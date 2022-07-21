#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Each letter of the alphabet, arranged in the same relative index as POINTS
char ALPHA[] = "abcdefghijklmnopqrstuvwxyz";

int compute_score(string word);

// Calculates which word scores higher in a game of scrabble
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
    return (0);
}

// Scores the string argument, ignoring non-letter characters
int compute_score(string word)
{
    // Set score to zero
    int score = 0;

    // Iterates through each character in 'word' variable
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
        // Re-iterates the loop if the character is not a lette
        if (word[i] < 'a' || word[i] > 'z')
            continue;
        // Calculates the score of the letter character
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == ALPHA[j])
            {
                // Assign points
                score += POINTS[j];
                break;
            }
        }
    }
    return (score);
}

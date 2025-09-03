#include <stdio.h>
#include <string.h>

void title();
void guess(int* tries, char maxAttempts[26]);
int alreadyGuessed(char letter, char guesses[26], int tries);

int main()
{
    char secretWord[20];

    sprintf(secretWord, "WATERMELON APPLE");

    int success = 0;
    int hanged = 0;
    char maxAttempts[26];
    int tries = 0;

    title();

    do
    {
        for (int i = 0; i < strlen(secretWord); i++)
        {
            int found = alreadyGuessed(secretWord[i], maxAttempts, tries);

            if (found)
            {
                printf("%c ", secretWord[i]);
            }
            else
            {
                printf("_ ");
            }
        }
        printf("\n");

      guess(&tries, maxAttempts);
      

    } while (!success && !hanged);
}

void title()
{
    printf("*****************\n");
    printf("*    Hangman    *\n");
    printf("*****************\n\n");
}

void guess(int* tries, char maxAttempts[26])
{
    char guess;
    scanf(" %c", &guess);

    maxAttempts[(*tries)] = guess;
    (*tries)++;
}

int alreadyGuessed(char letter, char guesses[26], int tries)
{
    int found = 0;
    for (int j = 0; j < tries; j++)
    {
        if (guesses[j] == letter)
        {
            found = 1;
            break;
        }
    }
    return found;
}
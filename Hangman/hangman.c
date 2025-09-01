#include <stdio.h>
#include <string.h>

void title();
void guess(int tries, char maxAttempts[26]);

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
            int found = 0;

            for (int j = 0; j < tries; j++)
            {
                if (maxAttempts[j] == secretWord[i])
                {
                    found = 1;
                    break;
                }
            }

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

      guess(tries, maxAttempts);
      tries++;

    } while (!success && !hanged);
}

void title()
{
    printf("*****************\n");
    printf("*    Hangman    *\n");
    printf("*****************\n\n");
}

void guess(int tries, char maxAttempts[26])
{
    char guess;
    scanf(" %c", &guess);

    maxAttempts[tries] = guess;
}
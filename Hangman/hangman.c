#include <stdio.h>
#include <string.h>

char secretWord[20];
char guesses[26];
int attempts = 0;

void title();
void guess();
int alreadyGuessed(char letter);
int hanged();
int victory();
void drawGallows();
void pickWord()
{
    sprintf(secretWord, "WATERMELON");
}

int main()
{
    

    pickWord();
    title();

    do
    {
        drawGallows();
        guess();
    } while (!victory() &&!hanged());
}

void title()
{
    printf("*****************\n");
    printf("*    Hangman    *\n");
    printf("*****************\n\n");
}

void guess()
{
    char guess;
    scanf(" %c", &guess);
    guesses[attempts] = guess;
    attempts++;
}

int alreadyGuessed(char letter)
{
    int found = 0;
    for (int j = 0; j < attempts; j++)
    {
        if (guesses[j] == letter)
        {
            found = 1;
            break;
        }
    }
    return found;
}

void drawGallows()
{
    for (int i = 0; i < strlen(secretWord); i++)
    {
        int found = alreadyGuessed(secretWord[i]);

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
}

int hanged()
{
    int mistakes = 0;
    for (int i = 0; i < attempts; i++)
    {
        int exists = 0;

        for (int j = 0; j < strlen(secretWord); j++)
        {
            if (guesses[i] == secretWord[j])
            {
                exists = 1;
                break;
            }
        }
        if (!exists)
            mistakes++;
    }
    return mistakes >= 5;
}

int victory() {
    for(int i = 0; i < strlen(secretWord); i++) {
        if(!alreadyGuessed(secretWord[i])) {
            return 0;
        }
    }
    return 1;
}
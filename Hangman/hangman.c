#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "hangman.h"

char secretWord[20];
char guesses[26];
int attempts = 0;

void pickWord()
{
    FILE *f;
    f = fopen("words.txt", "r");
    if (f == 0)
    {
        printf("Sorry, word database unavailable.\n\n");
        exit(1);
    }

    int numberOfWords;
    fscanf(f, "%d", &numberOfWords);

    srand(time(0));
    int random = rand() % numberOfWords;

    for (int i = 0; i <= random; i++)
    {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
}

int main()
{
    pickWord();
    title();

    do
    {
        drawGallows();
        guess();
    } while (!victory() && !hanged());
    addWord();
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

int victory()
{
    for (int i = 0; i < strlen(secretWord); i++)
    {
        if (!alreadyGuessed(secretWord[i]))
        {
            return 0;
        }
    }
    return 1;
}

void addWord()
{

    char option;
    printf("Would you like to add a new word to the game? (Y/N)");
    scanf(" %c", &option);

    if (option == 'Y')
    {
        char newWord[20];
        printf("Type your new word: ");
        scanf("%s", newWord);

        FILE *f;
        f = fopen("words.txt", "r+");
        if (f == 0)
        {
            printf("Sorry, word database unavailable.\n\n");
            exit(1);
        }

        int amount;
        fscanf(f, "%d", &amount);
        amount++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", amount);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", newWord);

        fclose(f);
    }
}
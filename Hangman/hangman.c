#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "hangman.h"

char secretWord[TAMANHO_PALAVRA];
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

    if (victory())
    {
        printf("\nCONGRATULATIONS!! YOU FOUND THE SECRET WORD!!");
    }
    else
    {
        printf("\nOH NO, YOU'VE BEEN HANGED!!\nTHE SECRET WORD WAS: ");
        for (int i = 0; i < strlen(secretWord); i++)
        {
            printf("%c", toupper(secretWord[i]));
        }
    }

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
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    guess = toupper(guess);

if (charExists(guess))
{
    printf("\nCorrect: the word has the letter %c\n\n", guess);
} else {
    printf("\nWrong: the word does NOT have the letter %c\n\n", guess);
}


    guesses[attempts] = guess;
    attempts++;
}

int alreadyGuessed(char letter)
{
    int found = 0;
    for (int j = 0; j < attempts; j++)
    {
        if (guesses[j] == toupper(letter))
        {
            found = 1;
            break;
        }
    }
    return found;
}

void drawGallows()
{
    int mistakes = countMistakes();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (mistakes >= 1 ? '(' : ' '),
           (mistakes >= 1 ? '_' : ' '), (mistakes >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (mistakes >= 3 ? '\\' : ' '),
           (mistakes >= 2 ? '|' : ' '), (mistakes >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (mistakes >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (mistakes >= 4 ? '/' : ' '),
           (mistakes >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(secretWord); i++)
    {
        int found = alreadyGuessed(secretWord[i]);

        if (found)
        {
            printf("%c ", toupper(secretWord[i]));
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

int charExists(char character) {

    for (int j = 0; j < strlen(secretWord); j++)
    {
        if (character == toupper(secretWord[j]))
        {
            return 1;
        }
    }
    return 0;
}

int countMistakes()
{
    int mistakes = 0;
    for (int i = 0; i < attempts; i++)
    {
        if (!charExists(guesses[i]))
            mistakes++;
    }
    return mistakes;
}

int hanged()
{
    return countMistakes() >= 5;
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
    printf("\nWould you like to add a new word to the game? (Y/N)");
    scanf(" %c", &option);

    option = toupper(option);

    if (option == 'Y')
    {
        char newWord[TAMANHO_PALAVRA];
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
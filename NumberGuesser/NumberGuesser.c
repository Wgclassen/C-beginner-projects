#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("*****************************\n");
    printf("* Welcome to number guesser *\n");
    printf("*****************************\n");

    srand(time(0));
    int secretNumber = rand() % 100;
    int guess;
    int guessNumber = 0;
    int level = 0;

    double score = 1000.0;

    printf("\nChoose your difficulty level:");
    printf("\n\n(1) Easy, (2) Medium, (3) Hard\n");
    scanf("%d", &level);

    int tries;

    switch (level)
    {
    case 1:
        tries = 20;
        break;

    case 2:
        tries = 15;
        score += 100;
        break;

    case 3:
        tries = 6;
        score += 200;
        break;

    default:
        printf("\n\nInvalid level selected, defaulting to Medium");
        tries = 15;
        break;
    }

    for(int i = 1; i <= tries; i++)
    {
        guessNumber++;
        printf("\nGUESS #%d\n", guessNumber);
        printf("Guess a number: ");
        scanf("%d", &guess);

        if (guess < 0)
        {
            printf("You can't guess negative numbers!\n");
            continue;
        }

        int success = (guess == secretNumber);
        int higher = guess > secretNumber;
        int lower = guess < secretNumber;

        printf("\nYour guess was %d", guess);

        if (success)
        {
            printf("\nCongratulations! You found the secret number in %d guesses!", guessNumber);
            printf("\nYour final score was %.1f.", score);
            break;
        }
        else if (higher)
        {
            printf("\nYour pick is higher than the secret number, try again!");
        }
        else
        {
            printf("\nYour pick is lower than the secret number, try again!");
        }
        score = score - abs(guess - secretNumber) / 2.0;
    }
}
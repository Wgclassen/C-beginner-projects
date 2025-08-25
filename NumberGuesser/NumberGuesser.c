#include <stdio.h>

int main()
{
    printf("*****************************\n");
    printf("* Welcome to number guesser *\n");
    printf("*****************************\n");

    int secretNumber = 42;
    int guess;
    int guessNumber = 0;
    double score = 1000.0;

    while (1)
    {
        guessNumber++;
        printf("\nGUESS #%d\n", guessNumber);
        printf("Guess a number: ");
        scanf("%d", &guess);
    
        if(guess < 0) {
            printf("You can't guess negative numbers!\n");;
            continue;
        }
    
        int success = (guess == secretNumber);
        int higher = guess > secretNumber;
        int lower = guess < secretNumber;
    
        printf("\nYour guess was %d", guess);
    
        if (success)
        {
            printf("\nCongratulations! You found the secret number in %d guesses!", guessNumber);
            printf("\nYour final score was %f.", score);
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
        score = score - ((guess - secretNumber)/2.0);
    }
}
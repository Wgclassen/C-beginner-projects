#include <stdio.h>

int main () {
    printf("*****************************\n");
    printf("* Welcome to number guesser *\n");
    printf("*****************************\n");

    int secretNumber = 42;
    int guess;

    printf("Guess a number: ");
    scanf("%d", &guess);
    printf("\nYour guess was %d", guess);

    int success = (guess == secretNumber);

    if(success) {
        printf("\nCongratulations! You found the secret number!");
    } else {
        if (guess > secretNumber){
            printf("\nYour pick is higher than the secret number, try again!");
        } else {
            printf("\nYour pick is lower than the secret number, try again!");
        }
    }
}


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
}


#include <stdio.h>
#include <string.h>

int main() {
    char secretWord[20];

    sprintf(secretWord, "WATERMELON APPLE");

    printf("%s", secretWord);

    int success = 0;
    int hanged = 0;

    do {
        char guess;
        scanf("%c", &guess);

        for (int i = 0; i < strlen(secretWord); i++)
        {
            if(secretWord[i] == guess) {
                printf("The position %d has this letter\n", i);
            }
        }
        
    } while (!success && !hanged);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    // Exercise 1 - Create an array of integers (int) with 10 positions. Fill it with the values 10, 20, 30, 40, 50, 60, 70, 80, 90 and 100. Use a for loop to print the array values.
    printf("EXERCISE 1:");
    int exercise1Array[10];
    for (int i = 1; i <= 10; i++)
    {
        exercise1Array[i - 1] = i * 10;
        printf("\nArray position %d: %d", i, exercise1Array[i - 1]);
    }
    printf("\n\n=============\n\n");

    // Exercise 2 - Create an array of characters (char) with 16 positions (4x4). Fill it with a, b, c (...) n, o, p. Use two for loops to print the array values.
    printf("EXERCISE 2:");
    char exercise2Array[4][4];
    char *source = "abcdefghijklmnop";
    memcpy(exercise2Array, source, 16);
    for (int row = 0; row < 4; row++)
    {
        printf("\n");
        for (int col = 0; col < 4; col++)
        {
            printf("%c ", exercise2Array[row][col]);
        }
    }
    printf("\n\n=============\n\n");

    // Exercise 3 - Write a 10 element array filled with int numbers, then allow the user to type a positive integer to be searched in the array. If the value exists within the array, print it's location, otherwise state that the value doesn't exist.
    printf("EXERCISE 3:");
    char exercise3Array[10];
    for (int i = 0; i < 10; i++)
    {
        exercise3Array[i] = rand() % 100;
    }
    printf("\nType a positive number between 0 and 99: ");
    int userInput;
    scanf("%d", &userInput);
    if (userInput < 0 || userInput > 99)
    {
        printf("\nInvalid input! Please input a positive number between 0 and 99");
    }
    int foundNumber = 0;
    for (int i = 0; i < 10; i++)
    {
        if (userInput == exercise3Array[i])
        {
            printf("\nNumber %d found in the array position %d", userInput, i);
            foundNumber = 1;
        }
    }
    if (!foundNumber)
    {
        printf("\nThe number %d doesn't exist within the array", userInput);
    }
    printf("\nThe numbers contained within the array were: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", exercise3Array[i]);
    }
    printf("\n\n=============\n\n");

    // Exercise 4 - Write a program with a 3x3 array of integer elements. Calculate and print the sum of the elements in each row of the array.
    printf("EXERCISE 4:");
    int exercise4Array[3][3];
    printf("\n\nArray elements:");
    for (int row = 0; row < 3; row++)
    {
        printf("\n");
        for (int col = 0; col < 3; col++)
        {
            exercise4Array[row][col] = rand() % 100;
            printf("%d ", exercise4Array[row][col]);
        }
    }
    printf("\n\nSum of each array row:");
    for (int row = 0; row < 3; row++)
    {
        int sumOfRow = 0;
        printf("\n");
        for (int col = 0; col < 3; col++)
        {
            sumOfRow += exercise4Array[row][col];
            printf("%d ", exercise4Array[row][col]);
            if (col < 2)
            {
                printf("+ ");
            }
            else
            {
                printf("= %d", sumOfRow);
            }
        }
    }
    printf("\n\n=============\n\n");

    // Exercise 5 - Write a 5x5 array of integers (positive or negative, random or of your choice). Find and print the largest element in the array.
    printf("EXERCISE 5:");
    int exercise5Array[5][5];
    printf("\n\nArray elements:");
    for (int row = 0; row < 5; row++)
    {
        printf("\n");
        for (int col = 0; col < 5; col++)
        {
            exercise5Array[row][col] = rand() % 100;
            printf("%d ", exercise5Array[row][col]);
        }
    }

    int largestNumber = 0;
    for (int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            if(largestNumber < exercise5Array[row][col]) {
                largestNumber = exercise5Array[row][col];
            }
        }
    }

    printf("\n\nThe largest element in the array is: %d", largestNumber);
}
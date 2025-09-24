#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eatman.h"
#include "map.h"
#include "ui.h"

MAP map;
POSITION hero;
int hasPowerup = 0;

int main()
{
    readMap(&map);
    findMap(&map, &hero, HERO);

    do
    {
        printf("POWERUP: %s\n", (hasPowerup ? "YES" : "NO"));
        printMap(&map);
        char input;
        scanf(" %c", &input);
        move(input);
        if (input == BOMB)
            usePowerup();

        ghostMovement();
    } while (!gameOver());

    printMap(&map);

    freeMap(&map);
}

int gameOver()
{
    POSITION position;

    int defeat = !findMap(&map, &position, HERO);
    int victory = !findMap(&map, &position, GHOST);

    return victory || defeat;
}

int isDirection(char direction)
{
    return direction == LEFT ||
           direction == UP ||
           direction == DOWN ||
           direction == RIGHT;
}

void move(char direction)
{
    if (!isDirection(direction))
        return;

    int targetX = hero.x;
    int targetY = hero.y;

    switch (direction)
    {
    case LEFT:
        targetY--;
        break;
    case UP:
        targetX--;
        break;
    case DOWN:
        targetX++;
        break;
    case RIGHT:
        targetY++;
        break;
    default:
        break;
    }

    if (!canMove(&map, HERO, targetX, targetY))
        return;

    if (isCharacter(&map, POWERUP, targetX, targetY))
    {
        hasPowerup = 1;
    }

    mapMovement(&map, hero.x, hero.y, targetX, targetY);

    hero.x = targetX;
    hero.y = targetY;
}

int ghostDirection(int startingX, int startingY, int *targetX, int *targetY)
{
    int options[4][2] = {
        {startingX, startingY + 1},
        {startingX + 1, startingY},
        {startingX, startingY - 1},
        {startingX - 1, startingY}};

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int position = rand() % 4;
        if (canMove(&map, GHOST, options[position][0], options[position][1]))
        {
            *targetX = options[position][0];
            *targetY = options[position][1];

            return 1;
        }
    }
    return 0;
}

void ghostMovement()
{
    MAP copy;
    copyMap(&copy, &map);

    for (int x = 0; x < map.rows; x++)
    {
        for (int y = 0; y < map.cols; y++)
        {
            if (copy.matrix[x][y] == GHOST)
            {

                int targetX;
                int targetY;

                int foundPath = ghostDirection(x, y, &targetX, &targetY);

                if (foundPath)
                {
                    mapMovement(&map, x, y, targetX, targetY);
                }
            }
        }
    }
    freeMap(&copy);
}

void usePowerup()
{
    if(!hasPowerup) return;

    powerupExplosion(hero.x, hero.y, 0, 1, 3);
    powerupExplosion(hero.x, hero.y, 0, -1, 3);
    powerupExplosion(hero.x, hero.y, 1, 0, 3);
    powerupExplosion(hero.x, hero.y, -1, 0, 3);

    hasPowerup = 0;
}

void powerupExplosion(int x, int y, int sumX, int sumY, int range)
{
    if (range == 0)
        return;

    int newX = x+sumX;
    int newY = y+sumY;
    map.matrix[x][y + 1] = EMPTY;
    powerupExplosion(x, y + 1, newX, newY, range - 1);
}
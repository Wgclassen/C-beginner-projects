#include <stdio.h>
#include <stdlib.h>
#include "eatman.h"
#include "map.h"

MAP map;
POSITION hero;

int main()
{
    readMap(&map);
    findMap(&map, &hero, '@');

    do
    {
        printMap(&map);
        char input;
        scanf(" %c", &input);
        move(input);
    } while (!gameOver());

    printMap(&map);

    freeMap(&map);
}

int gameOver()
{
    return 0;
}

void move(char direction)
{
    if (direction != 'a' &&
        direction != 'w' &&
        direction != 's' &&
        direction != 'd')
        return;

    int targetX = hero.x;
    int targetY = hero.y;

    switch (direction)
    {
    case 'a':
        targetY--;
        break;
    case 'w':
        targetX--;
        break;
    case 's':
        targetX++;
        break;
    case 'd':
        targetY++;
        break;
    default:
        break;
    }

    if (targetX >= map.rows ||
        targetY >= map.cols ||
        map.matrix[targetX][targetY] != '.')
        return;
    
    map.matrix[targetX][targetY] = '@';
    map.matrix[hero.x][hero.y] = '.';
    hero.x = targetX;
    hero.y = targetY;
}
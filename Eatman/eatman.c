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

    map.matrix[hero.x][hero.y] = '.';

    switch (direction)
    {
    case 'a':
        map.matrix[hero.x][hero.y - 1] = '@';
        hero.y--;
        break;
    case 'w':
        map.matrix[hero.x - 1][hero.y] = '@';
        hero.x--;
        break;
    case 's':
        map.matrix[hero.x + 1][hero.y] = '@';
        hero.x++;
        break;
    case 'd':
        map.matrix[hero.x][hero.y + 1] = '@';
        hero.y++;
        break;
    default:
        break;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "map.h"

char spriteGhost[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char spriteWall[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char spriteHero[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char spritePowerup[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char spriteEmpty[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

void printMap(MAP *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        for (int part = 0; part < 4; part++)
        {
            for (int j = 0; j < map->cols; j++)
            {
                switch (map->matrix[i][j])
                {
                case GHOST:
                    printSprite(spriteGhost, part);
                    break;
                case HERO:
                    printSprite(spriteHero, part);
                    break;
                case WALL_HORIZONTAL:
                case WALL_VERTICAL:
                    printSprite(spriteWall, part);
                    break;
                case EMPTY:
                    printSprite(spriteEmpty, part);
                    break;
                case POWERUP:
                    printSprite(spritePowerup, part);
                    break;
                }
            }
            printf("\n");
        }
    }
}

void printSprite(char sprite[4][7], int part)
{
    printf("%s", sprite[part]);
}

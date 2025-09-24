#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void readMap(MAP *map)
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (f == 0)
    {
        printf("Error when reading map\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(map->rows), &(map->cols));

    allocateMap(map);

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map->matrix[i]);
    }
    fclose(f);
}

void allocateMap(MAP *map)
{
    map->matrix = malloc(sizeof(char *) * map->rows);
    for (int i = 0; i < map->rows; i++)
    {
        map->matrix[i] = malloc(sizeof(char) * (map->cols + 1));
    }
}

int findMap(MAP *map, POSITION *position, char c)
{
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->cols; j++)
        {
            if (map->matrix[i][j] == c)
            {
                position->x = i;
                position->y = j;
                return 1;
            }
        }
    }
    return 0;
}

void freeMap(MAP *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        free(map->matrix[i]);
    }
    free(map->matrix);
}

int isValid(MAP *map, int targetX, int targetY)
{
    if (targetX >= map->rows ||
        targetY >= map->cols)
        return 0;

    return 1;
}

void copyMap(MAP *target, MAP *origin)
{
    target->rows = origin->rows;
    target->cols = origin->cols;

    allocateMap(target);
    for (int i = 0; i < origin->rows; i++)
    {
        strcpy(target->matrix[i], origin->matrix[i]);
    }
}

void mapMovement(MAP *map, int startingX, int startingY, int targetX, int targetY)
{
    char character = map->matrix[startingX][startingY];
    map->matrix[targetX][targetY] = character;
    map->matrix[startingX][startingY] = EMPTY;
}

int isWall(MAP *map, int x, int y)
{
    return map->matrix[x][y] == WALL_VERTICAL || map->matrix[x][y] == WALL_HORIZONTAL;
}

int isCharacter(MAP *map, char character, int x, int y)
{
    return map->matrix[x][y] == character;
}

int canMove(MAP *map, char character, int x, int y)
{
    return isValid(map, x, y) && !isWall(map, x, y) && !isCharacter(map, character, x, y);
}
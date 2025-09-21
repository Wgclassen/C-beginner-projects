#include <stdio.h>
#include <stdlib.h>
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

void allocateMap(MAP* map)
{
    map->matrix = malloc(sizeof(char *) * map->rows);
    for (int i = 0; i < map->rows; i++)
    {
        map->matrix[i] = malloc(sizeof(char) * (map->cols + 1));
    }
}

void findMap(MAP* map, POSITION* position, char c) {
    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->cols; j++)
        {
            if (map->matrix[i][j] == c)
            {
                position->x = i;
                position->y = j;
                break;
            }
        }
    }
}

void printMap(MAP *map)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map->matrix[i]);
    }
}

void freeMap(MAP *map)
{
    for (int i = 0; i < map->rows; i++)
    {
        free(map->matrix[i]);
    }
    free(map->matrix);
}
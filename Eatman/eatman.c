#include <stdio.h>
#include <stdlib.h>
#include "eatman.h"
char **map;

int rows;
int cols;

int main()
{

    readMap();

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }

    freeMap();
}

void freeMap()
{
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
}

void readMap()
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (f == 0)
    {
        printf("Error when reading map\n");
        exit(1);
    }

    fscanf(f, "%d %d", &rows, &cols);

    allocateMap();

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map[i]);
    }
    fclose(f);
}

void allocateMap()
{
    map = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(sizeof(char) * (cols + 1));
    }
}
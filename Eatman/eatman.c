#include <stdio.h>
#include <stdlib.h>
char** map;

int rows;
int cols;
int main()
{

    FILE *f;
    f = fopen("map.txt", "r");
    if (f == 0)
    {
        printf("Error when reading map\n");
        exit(1);
    }

    fscanf(f, "%d %d", &rows, &cols);

    map = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(sizeof(char) * (cols + 1));
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }

    fclose(f);
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
}
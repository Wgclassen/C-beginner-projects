struct map
{
    char **matrix;
    int rows;
    int cols;
};

typedef struct map MAP;

struct position 
{
    int x;
    int y;
};

typedef struct position POSITION;

void readMap(MAP *map);
void freeMap(MAP *map);
void findMap(MAP *map, POSITION *position, char c); 
void allocateMap(MAP *map);
void printMap(MAP *map);
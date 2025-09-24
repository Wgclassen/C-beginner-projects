#define HERO '@'
#define GHOST 'G'
#define EMPTY '.'
#define WALL_VERTICAL '|'
#define WALL_HORIZONTAL '-'

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
int isValid(MAP *map, int targetX, int targetY);
int isEmpty(MAP *map, int targetX, int targetY);
void mapMovement(MAP *map, int startingX, int startingY, int targetX, int targetY);
void copyMap(MAP *target, MAP *origin);
int canMove(MAP *map, int x, int y);
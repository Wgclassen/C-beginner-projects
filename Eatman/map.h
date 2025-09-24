#ifndef _MAP_H_
#define _MAP_H_

#define HERO '@'
#define GHOST 'G'
#define POWERUP 'P'
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
int findMap(MAP *map, POSITION *position, char c); 
void allocateMap(MAP *map);
int isValid(MAP *map, int targetX, int targetY);
int isWall(MAP *map, int x, int y);
int isCharacter(MAP *map, char character, int x, int y);
void mapMovement(MAP *map, int startingX, int startingY, int targetX, int targetY);
void copyMap(MAP *target, MAP *origin);
int canMove(MAP *map, char character, int x, int y);

#endif
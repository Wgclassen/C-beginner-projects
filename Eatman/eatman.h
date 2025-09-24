#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

int gameOver();
void move(char direction);
int isDirection(char direction);
void ghostMovement();
int ghostDirection(int startingX, int startingY, int *targetX, int *targetY);
void usePowerup();
void powerupExplosion(int x, int y, int sumX, int sumY, int range);
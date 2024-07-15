#ifndef _FOGE_FOGE_H_
#define _FOGE_FOGE_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define NUM_OF_GHOSTS 2
#define BOMBA 'b'

// Function to read a single character without pressing Enter
char getch();

// True if the games is over
bool over();

// makes the movement of the role passed
bool move(char dir, char role);

// Returns if the key pressed is for a direction
bool isdirection (char dir);

// Controls the ghost moves
void moveghosts();

// Call the explosions on the locations wanted
void explodepill(int x, int y);

// Realize the explosion
void explode(int x, int y);

#endif
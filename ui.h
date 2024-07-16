#ifndef _UI_H_
#define _UI_H_

#include "mapa.h"

// print the line of index 'parte' of the matriz 'desenho'
void printpart(char desenho[4][7], int parte);

// controls the logic of printing the map with the paints of each part of the map
void printmap(Mapa m);

#endif
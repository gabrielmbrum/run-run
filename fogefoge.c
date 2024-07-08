#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fogefoge.h"
#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

Mapa mapa;
Posicao heroi;

void move (char dir, char role) {
    if (dir != CIMA &&
            dir != BAIXO &&
            dir != ESQUERDA &&
            dir != DIREITA)
        return;

    int proximox = heroi.x, proximoy = heroi.y;

    switch (dir) {
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case ESQUERDA:
            proximoy++;
            break;
        case DIREITA:
            proximoy--;
            break;
    }

    if (canwalk(&mapa, role, proximox, proximoy))
}

int main () {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("ERROR DURING OPENING THE FILE 'mapa.txt'\n");
        return 0;
    }

    fscanf(f, "%d %d", &M, &N);
    printf("linhas: %d | colunas: %d\n", M, N);

    mapa = malloc(sizeof(char*) * M);
    for (int i = 0; i < M; i++) {
        mapa[i] = malloc(sizeof(char) * (N+1)); //+1 por conta do '\n'
    }

    for (int i = 0; i < M; i++) {
        fscanf(f, "%s", mapa[i]);
        printf("%s\n", mapa[i]);
    }

    fclose(f);
}
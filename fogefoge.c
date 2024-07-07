#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fogefoge.h"
#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

Mapa m;
Posicao heroi;

void printmap (Mapa m) {
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

void alocatemap (Mapa *m) {
    (*m).matriz = malloc(sizeof(char*) * (*m).linhas);

    for (int i = 0; i < m->linhas; i++) 
        m->matriz[i] = malloc(sizeof(char) * (*m).colunas);
}

void readmap (Mapa *m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("ERROR DURING OPENING THE FILE 'mapa.txt'\n");
        return;
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
}

void freemap (Mapa *m) {
    for (int i = 0; i < m->linhas; m++)
        free(m->matriz[i]);
    free(m->matriz);
}

void findmap (Mapa *m, Posicao *p, char c) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return;
            }
        }
    }
}

bool cango () {

}

void move (char dir) {
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

    if (cango(heroi, proximox, proximoy))
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
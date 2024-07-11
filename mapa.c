#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mapa.h"

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
    alocatemap(m);

    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void freemap (Mapa *m) {
    for (int i = 0; i < m->linhas; m++)
        free(m->matriz[i]);
    free(m->matriz);
}

bool findhero (Mapa *m, Posicao *p) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == HEROI) {
                p->x = i;
                p->y = j;
                return true;
            }
        }
    }

    return false;
}

bool findghosts() {}

bool isvalid (Mapa *m, int x, int y) {
    return (m->linhas > x && m->colunas > y);
}

bool iswall (Mapa *m, int x, int y) {
    return (m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL);
}

bool ischaracter (Mapa *m, char personagem, int x, int y) {
    return (m->matriz[x][y] == personagem);
}

bool canwalk (Mapa *m, char personagem, int x, int y) {
    return 
        isvalid(m, x, y) &&
        !iswall(m, x, y) &&
        !ischaracter(m, personagem, x, y);
}

void walkonmap(Mapa* m, int xori, int yori, int xdes, int ydes) {
    
    m->matriz[xdes][ydes] = m->matriz[xori][yori];
    m->matriz[xori][yori] = VAZIO;
}
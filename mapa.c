#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mapa.h"

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

void alocatemap (Mapa *m) {
    (*m).matriz = malloc(sizeof(char*) * (*m).linhas);

    for (int i = 0; i < m->linhas; i++) 
        m->matriz[i] = malloc(sizeof(char) * (*m).colunas);
}


void freemap (Mapa *m) {
    for (int i = 0; i < m->linhas; m++)
        free(m->matriz[i]);
    free(m->matriz);
}

void printmap (Mapa m) {
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
}

bool findmap (Mapa *m, Posicao *p, char c) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return true;
            }
        }
    }

    return false;
}

bool canwalk (Mapa *m, char personagem, int x, int y) {

}
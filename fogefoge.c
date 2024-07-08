#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <termio.h>
#include "fogefoge.h"
#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

Mapa mapa;
Posicao heroi;

// Function to read a single character without pressing Enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    struct termios new = {0};

    // Get current terminal attributes
    if (tcgetattr(STDIN_FILENO, &old) < 0) {
        perror("tcgetattr()");
        return 1;
    }

    // Copy old terminal attributes to new settings
    new = old;

    // Disable canonical mode and echo
    new.c_lflag &= ~(ICANON | ECHO);

    // Set minimum number of characters for non-canonical read and timeout
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;

    // Apply new terminal settings immediately
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new) < 0) {
        perror("tcsetattr ICANON");
        return 1;
    }

    // Read a single character
    if (read(STDIN_FILENO, &buf, 1) < 0) {
        perror("read()");
        return 1;
    }

    // Restore old terminal settings
    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
        return 1;
    }

    return buf;
}

bool acabou() {
    Posicao pos;
    bool ganhou = !findmap(&mapa, &pos, HEROI);
    //bool perdeu = !findmap(&mapa, &pos, FANTASMA);

    return 0;
}

bool isdirection (char dir) {
    return (dir == CIMA || dir == BAIXO || dir == ESQUERDA || dir == DIREITA);
}

void move (char dir, char role) {
    if (!isdirection(dir))
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
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if (canwalk(&mapa, role, proximox, proximoy)) {
        walkonmap(&mapa, heroi.x, heroi.y, proximox, proximoy);
        heroi.x = proximox;
        heroi.y = proximoy;
    }
}

int main () {
    readmap(&mapa);
    findmap(&mapa, &heroi, HEROI);

    do {
        system("clear");
        printmap(mapa);

        char comando = getch();
        //scanf(" %c", &comando);

        move(comando, HEROI);
    } while (!acabou());

    freemap(&mapa);
}

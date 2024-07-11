#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <termio.h>
#include "fogefoge.h"
#include "mapa.h"

Mapa mapa;
Posicao heroi;
Posicao* ghosts;

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

bool over() {
    Posicao pos;
    bool loose = !find(mapa, heroi, HEROI);
    //bool win = !findmap(&mapa, &pos, FANTASMA);

    return (loose);
}

bool isdirection (char dir) {
    return (dir == CIMA || dir == BAIXO || dir == ESQUERDA || dir == DIREITA);
}

bool move (char dir, char role) {
    if (!isdirection(dir))
        return true;

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
        if (walkonmap(&mapa, heroi.x, heroi.y, proximox, proximoy)) {
            heroi.x = proximox;
            heroi.y = proximoy;

        } else return false; // Hero died
    }

    return true;
}

void moveghosts() {
    srand(time(NULL));
    for (int i = 0; i < mapa.numofghosts; i++) {
        int nextx, nexty;
        int count = 0, random;

        do {
            nextx = ghosts[i].x;
            nexty = ghosts[i].y;
            random = rand() % 4;
            count++;
            switch (random) {
                case 0: nextx++; break;
                case 1: nextx--; break;
                case 2: nexty++; break;
                case 3: nexty--; break;
            }

        } while (count < 7 && !canwalk(&mapa, FANTASMA, nextx, nexty));
        
        walkonmap(&mapa, ghosts[i].x, ghosts[i].y, nextx, nexty);
        ghosts[i].x = nextx;
        ghosts[i].y = nexty;
    }
}

int main () {
    readmap(&mapa);
    findhero(&mapa, &heroi);
    findghosts(&mapa, &ghosts);

    do {
        system("clear");
        //printf("\n");
        printmap(mapa);

        char comando = getch();
        //scanf(" %c", &comando);

        if (move(comando, HEROI))
            moveghosts();
        //printf("moveu fan\n");
    } while (!over());
    printf("GAME OVER!!!\n");
    printmap(mapa);
    freemap(&mapa);
}

#include <stdio.h>
#include <stdbool.h>
#include "mapa.h"

char desenhoparede[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenhofantasma[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhoheroi[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void printpart(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void printmap(Mapa m) {
	for(int i = 0; i < m.linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < m.colunas; j++) {

				switch(m.matriz[i][j]) {
					case FANTASMA:
                        printf("\033[0;31m");
						printpart(desenhofantasma, parte);
                        printf("\033[0m");
						break;
					case HEROI:
						printf("\033[0;34m");
                        printpart(desenhoheroi, parte);
                        printf("\033[0m");
						break;
					case PILULA:
                        printf("\033[;32m");
						printpart(desenhopilula, parte);
						printf("\033[0m");
                        break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						printpart(desenhoparede, parte);
						break;
					case VAZIO:
						printpart(desenhovazio, parte);
						break;
				}
				
			}
			printf("\n");
		}

	}
}
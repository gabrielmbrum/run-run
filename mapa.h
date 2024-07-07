#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL ''
#define 
#define  

typedef struct mapa {
    int linhas;
    int colunas;
    char** matriz;
} Mapa;

typedef struct posicao {
    int x, y;
} Posicao;

void printmap (Mapa m);
void alocatemap (Mapa *m);
void readmap (Mapa *m);
void freemap (Mapa *m);
void findmap (Mapa *m, Posicao *p, char c);


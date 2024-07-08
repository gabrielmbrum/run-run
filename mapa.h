#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define  FANTASMA 'F'

typedef struct mapa {
    int linhas;
    int colunas;
    char** matriz;
} Mapa;

void printmap (Mapa m);
void alocatemap (Mapa *m);
void readmap (Mapa *m);
void freemap (Mapa *m);

typedef struct posicao {
    int x, y;
} Posicao;

bool findmap (Mapa *m, Posicao *p, char c);
bool isvalid (Mapa *m, int x, int y);
bool ehparede (Mapa *m, int x, int y);

void walkonmap(Mapa* m, int xori, int yori, int xdes, int ydes);

bool canwalk(Mapa *m, char personagem, int x, int y);
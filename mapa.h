#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define  FANTASMA 'F'

typedef struct mapa {
    int linhas;
    int colunas;
    int numofghosts;
    char** matriz;
} Mapa;

// Print all lines of the map
void printmap (Mapa m);

// Alocate memory for the map
void alocatemap (Mapa *m);

// Read the map from the file 'mapa.txt'
void readmap (Mapa *m);

// Free alocated memory for the map
void freemap (Mapa *m);

typedef struct posicao {
    int x, y;
} Posicao;

// Function that returns true if finds on the positions passed the role wanted
bool find (Mapa m, Posicao pos, char role);

// Function that returns true if finds the HERO into the map and puts it position into the var passed
bool findhero (Mapa *m, Posicao *p);

// Function that returns true if finds the GHOSTS into the map and puts it position into the var passed
void findghosts(Mapa *m, Posicao** ghosts); 

// Returns true if the position is inside of the limits of the map
bool isvalid (Mapa *m, int x, int y);

// Returns true if the positions is a wall
bool iswall (Mapa *m, int x, int y);

// Returns true if the positions has the same character that it was passed
bool ischaracter (Mapa *m, char personagem, int x, int y);

// Swap the content of origin and destination
bool walkonmap(Mapa* m, int xori, int yori, int xdes, int ydes);

// Returns true if it's possible to walk to the position passed
bool canwalk(Mapa *m, char personagem, int x, int y);
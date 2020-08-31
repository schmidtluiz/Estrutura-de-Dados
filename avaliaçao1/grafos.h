#define ERRO_COORDENADA_INVALIDA -1
#define ERRO_MATRIZES_INCOMPATIVEIS -2
#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
	int **m;
	int lin, col;
} MatrizDinamica;

int inicializa_matriz(MatrizDinamica *p, int l, int c);
void desaloca_matriz(MatrizDinamica *p);
void mostra_matriz(MatrizDinamica x);
int modifica_valor_matriz(MatrizDinamica *p, int i, int j, int valor);
int le_valor_matriz(MatrizDinamica x, int i, int j, int *pValor);

typedef struct{
   int *d; 
   int t;    
   int cap;
} Pilha;

void inicializa_pilha ( Pilha *a, int c );
int pilha_vazia ( Pilha a );
int pilha_cheia ( Pilha a );
int empilha ( Pilha *a, int inf );
int desempilha ( Pilha *a, int *inf );
int mostra_pilha ( Pilha a );
void desaloca_pilha( Pilha *a );

typedef struct{
   int *dados; // dados da fila 
   int inicio;     // índice do início da fila
   int n;          // quantidade de elementos da fila
   int capacidade;
} Fila;

void inicializa_fila ( Fila *p, int c );
int fila_vazia ( Fila f );
int fila_cheia ( Fila f );
int inserir ( Fila *p, int info );
int remover ( Fila *p, int *info );
void mostra_fila ( Fila f );
void desaloca_Fila( Fila *p );







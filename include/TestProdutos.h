typedef struct Produto {
	char Codigo_Produto[6];
	struct Produto *prox;
} *Produto;

Produto createProduto (Produto *it, char key[]);

void iterateP (int posTable, Produto mem[], char key[]);

void allocateP (char key[], Produto mem[]);

Produto* testProds (void);
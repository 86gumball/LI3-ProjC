typedef struct produto {
	char Codigo_Produto[6];
	struct produto *prox;
} *Produto;

int hashCodeProduto(char code_produto[]);

Produto createProduto (Produto it, char key[]);

void iterateProduto (int posTable, Produto mem[], char key[]);

void allocateProduto (char key[], Produto mem[]);

Produto* testProds (void);

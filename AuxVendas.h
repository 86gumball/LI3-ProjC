void copialimitada(char a[], char b[] , int n);

unsigned int codigo_Tudo (float preco, int unidades, int mes);

float devolve_Preco (unsigned int codigo_Extra);

int devolve_unidades (unsigned int codigo_Extra);

int devolve_mes (unsigned int codigo_Extra);

typedef struct venda {
	char produto[7];
	char compra;
	char cliente[6];
	unsigned int codigo_Extra;
	char filial;
	struct venda *prox;
} Venda;

void placeVenda (Venda p, Venda *memV[]);

void createVenda(Venda p, Venda *mem);
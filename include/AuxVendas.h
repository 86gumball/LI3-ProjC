unsigned int createPUM (float preco, int unidades, int mes);

float devolve_Preco (unsigned int codigoPUM);

int devolve_unidades (unsigned int codigoPUM);

int devolve_mes (unsigned int codigoPUM);

// const char produto ??
typedef struct venda {
	char code_produto[7];
	char compra;
	char code_cliente[6];
	unsigned int codigoPUM;
	char filial;
	struct venda *prox;
} *Venda;

void placeVenda (Venda p, Venda *memV);

Venda createVenda(Venda next, char code_produto[], char compra, char code_cliente[], unsigned int codigoPUM, char filial);

Venda cloneVenda(Venda outra);

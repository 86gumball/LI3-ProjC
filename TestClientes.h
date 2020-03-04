typedef struct cliente {
	char Codigo_Cliente[5];
	struct cliente *prox;
} *Cliente;

Cliente createCliente (Cliente *it, char key[]);

void iterate (int posTable, Cliente mem[], char key[], char pos);

void allocate (char key[], Cliente mem[]);

Cliente* testClientes (void);
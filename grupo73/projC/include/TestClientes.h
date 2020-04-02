//Estrutura do codigo cliente, forma de lista ligada
typedef struct cliente {
	//Armazenamento do codigo
	char Codigo_Cliente[5];
	//endereço da proxima estrutura de codigo cliente
	struct cliente *prox;
} *Cliente;
int hashCodeCliente(char code_cliente[]);

//Criação da estrutura de um cliente
Cliente createCliente (Cliente next, char key[]);

//Procura da posição para alocar o novo codigo, 
//sendo a posição chamada pela numeração do Codigo 
//(ex:A3590 -> posição 3590%4001 == posição 3590)
void iterate (int posTable, Cliente mem[], char key[]);

//Processo de desmembramento do codigo para iterar no array
void allocate (char key[], Cliente mem[]);

//Criação da tabela com os codigos todos do ficheiro
Cliente* testClientes (void);

#include <stdio.h>
#include <stdlib.h>
#include "../include/TestClientes.h"
#include "../include/stringUtils.h"

#define pathToClientes "../Dados Iniciais/Clientes.txt"

// Requires: code_cliente é do tipo: Axxxx
// Requires: 1000 <= xxxx <= 5000
int hashCodeCliente(char code_cliente[]){
    int key = stoi(code_cliente + 1);
    key = key % 4001;
    return key;
}

Cliente createCliente (Cliente next, char key[]) {
	Cliente new = (Cliente) malloc (sizeof (struct cliente)); 
	new->prox = next; 
	for (int i = 0; i < 5; i++) 
		new->Codigo_Cliente[i] = key[i]; 
	return new; 
}

// Requires: Não haja produtos repetidos a ser inseridos
void iterateCliente (int posTable, Cliente mem[], char key[]) {
    // it recebe a posição onde escrever
	Cliente *it = mem + (posTable % 4001);

    // Escreve-se no local para qual it aponta
	*it = createCliente (*it, key); 
}

void allocateCliente (char key[], Cliente mem[]) {
	//Posição na tabela 
	int posTable = stoi(key + 1);
	
	//Verificação da existência do codigo
	iterateCliente (posTable, mem, key);  
}

Cliente* testClientes (void) {
	//Abertura do ficheiro
	FILE *f = fopen (pathToClientes,"r");
	
	//Alocação de memória para guardares tudo
	Cliente *mem = malloc(4001 * sizeof(Cliente));

	//Buffer para guardar a String do codigo
	char buf[10];

	//Renovar as strings no buffer até ao fim do ficheiro
	while (fgets(buf,10,f))
		allocateCliente(buf,mem);
	
	fclose(f);

	return mem;
}

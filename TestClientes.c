#include <stdio.h>
#include <stdlib.h>
#include "TestClientes.h"

Cliente createCliente (Cliente *it, char key[]) {
	Cliente new = (Cliente) malloc (sizeof (struct cliente));
	new->prox = *it;
	for (int i = 0; i < 5; i++)
		new->Codigo_Cliente[i] = key[i];

	return new;
}

void iterate (int posTable, Cliente mem[], char key[], char pos) {
	Cliente *it = &mem[posTable%4001];

	while (*it != NULL && (*it)->Codigo_Cliente[0] != pos)
		it = &(*it)->prox;

	if (*it == NULL)
		*it = createCliente (it, key);

}

void allocate (char key[], Cliente mem[]) {
	char pos = key[0];
	int posTable = 0;
	int exp = 1000;
	for (int i = 1; i != '\r' && i != '\n'; i++) {
		posTable += (key[i]-'0') * exp;
		exp /= 10; 
	}
	
	iterate (posTable, mem, key, pos);
}

Cliente* testClientes (void) {
	FILE *f = fopen ("Dados Iniciais/Clientes.txt","r");
	
	Cliente *mem = malloc(4001 * sizeof(Cliente));

	char buf[10];
	int i;

	for (i = 0;fgets(buf,10,f); i++)
		allocate(buf,mem);
	
	fclose(f);

	return mem;
}



#include <stdio.h>
#include <stdlib.h>
#include "TestProdutos.h"

Produto createProduto (Produto *it, char key[], char pos[]) {
	Produto new = (Produto) malloc (sizeof (struct Produto));
	new->prox = *it;
	for (int i = 0; i < 6; i++)
		new->Codigo_Produto[i] = key[i];

	return new;
}

void iterateP (int posTable, Produto mem[], char key[], char pos[]) {
	Produto *it = &mem[posTable%9000];

	while (*it != NULL && ((*it)->Codigo_Produto[0] != pos[0] || (*it)->Codigo_Produto[1] != pos[1]))
		it = &(*it)->prox;

	if (*it == NULL)
		*it = createProduto (it, key, pos);

}

void allocateP (char key[], Produto mem[]) {
	char pos[2];
	pos[0] = key[0];
	pos[1] = key[1];
	int posTable = 0;
	int exp = 1000;
	for (int i = 2; i != '\r' && i != '\n'; i++) {
		posTable += (key[i]-'0') * exp;
		exp /= 10; 
	}
	
	iterateP (posTable, mem, key, pos);
}

Produto* testProds (void) {
	
	FILE *f = fopen ("Dados Iniciais/Produtos.txt","r");
	
	Produto *mem = malloc(9000 * sizeof(Produto));

	char buf[10];
	int i;

	for (i = 0;fgets(buf,10,f); i++)
		allocateP(buf,mem);
	
	fclose(f);

	return mem;
}

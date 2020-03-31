#include <stdio.h>
#include <stdlib.h>
#include "../include/TestProdutos.h"

#define pathToProdutos "../Dados Iniciais/Produtos.txt"

Produto createProduto (Produto next, char key[]) {
	Produto new = (Produto) malloc (sizeof (struct produto));
	new->prox = next;
	for (int i = 0; i < 6; i++)
		new->Codigo_Produto[i] = key[i];

	return new;
}

// Requires: Não haja produtos repetidos a ser inseridos
void iterateProduto (int posTable, Produto mem[], char key[]) {
    // posTable [1000..9999]
    // 1000 -> 1000
    // 8999 -> 8999
    // 9000 -> 0
    // 9001 -> 1
    // 9999 -> 999

	// Produto *it = &(mem[posTable%9000]);
	Produto *it = mem + (posTable % 9000);
	*it = createProduto (*it, key);
}

void allocateProduto (char key[], Produto mem[]) {
	int posTable = stoi(key + 2);
	//Introduçao
	iterateProduto (posTable, mem, key);
}

Produto* testProds (void) {
	//Carregar o apontador do ficheiro
	FILE *f = fopen (pathToProdutos,"r");
	
	//Alocar a memória á tabela
	Produto *mem = malloc(9000 * sizeof(Produto));

	//buffer para guardar cada linha lida do ficheiro
	char buf[10];

	//Leitura até ao final do ficheiro e alocação de produtos
	while (fgets(buf, 10, f))
		allocateProduto(buf, mem);
	
	//Fechar o ficheiro
	fclose(f);

	//Retornar a tabela
	return mem;
}

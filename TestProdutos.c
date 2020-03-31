#include <stdio.h>
#include <stdlib.h>
#include "TestProdutos.h"

Produto createProduto (Produto *it, char key[]) {
	Produto new = (Produto) malloc (sizeof (struct Produto));
	new->prox = *it;
	for (int i = 0; i < 6; i++)
		new->Codigo_Produto[i] = key[i];

	return new;
}

void iterateP (int posTable, Produto mem[], char key[]) {
	Produto *it = &mem[posTable%9000];

	while (*it != NULL && ((*it)->Codigo_Produto[0] != key[0] || (*it)->Codigo_Produto[1] != key[1]))
		it = &(*it)->prox;

	if (*it == NULL)
		*it = createProduto (it, key);

}

void allocateP (char key[], Produto mem[]) {
	//Posição na tabela
	int posTable = 0;
	//Expoente numérico
	int exp = 1000;
	//Leitura de String para numérico	
	for (int i = 2; i != '\r' && i != '\n'; i++) {
		//Adição de dos numeros usando o expoente (ex:'3'*1000+'2'*100+'1'*10+'0'*1)
		posTable += (key[i]+'0') * exp;
		exp /= 10; 
	}
	
	//Introduçao
	iterateP (posTable, mem, key);
}

Produto* testProds (void) {
	//Carregar o apontador do ficheiro
	FILE *f = fopen ("Dados Iniciais/Produtos.txt","r");
	
	//Alocar a memória á tabela
	Produto *mem = malloc(9000 * sizeof(Produto));

	//buffer para guardar cada linha
	char buf[10];

	//Leitura até ao final do ficheiro
	while (fgets(buf,10,f))
		//Identificação da posição
		allocateP(buf,mem);
	
	//Fechar o apontador
	fclose(f);

	//Retornar a tabela
	return mem;
}

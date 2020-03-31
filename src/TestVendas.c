#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AuxVendas.h"
#include "../include/TestProdutos.h"
#include "../include/TestClientes.h"

int cliente_Existe (Cliente *mem, char* verificar) {
	char key = verificar[0];

	int local = 0;
	int exp = 1000;

	for (int i = 1; i < 5; i++) {
		local += exp*(verificar[i] - '0');
		exp /= 10;
	}

	if (mem[local%4001] == NULL)
		return 0;

	Cliente *it = &mem[local%4001];

	while ((*it) != NULL) {
		if (key == (*it)->Codigo_Cliente[0])
			return 1;
		it = &(*it)->prox;
	}

	return 0;

}

int produto_Existe (Produto *mem, char* verificar) {
	char key[2];
	char cmp[2];

	copialimitada(key,verificar,2);

	int local = 0;
	int exp = 1000;

	for (int i = 2; i < 6; i++) {
		local += exp*(verificar[i] - '0');
		exp /= 10;
	}

	if (mem[local%9000] == NULL)
		return 0;

	Produto *it = &mem[local%9000];

	while ((*it) != NULL) {
		copialimitada(cmp,(*it)->Codigo_Produto, 2);
		if (strcmp(cmp,key))
			return 1;
		it = &(*it)->prox;
	}

	return 0;

}
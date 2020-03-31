#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AuxVendas.h"
#include "../include/TestProdutos.h"
#include "../include/TestClientes.h"

#define HashTableProduto Produto*
#define HashTableCliente Cliente*

// Confirmado que funciona
int cliente_Existe (HashTableCliente table, char code_cliente[]) {
    // produto key
	char pkey = code_cliente[0];
    // hkey = key na hashtable
    int hkey = hashCodeCliente(code_cliente);

	if (table[hkey] == NULL)
		return 0;

	Cliente it = table[hkey];

	while (it != NULL) {
		if (pkey == it->Codigo_Cliente[0])
			return 1;
		it = it->prox;
	}

	return 0;

}

// Confirmado que funciona
int produto_Existe (HashTableProduto table, char code_produto[]) {
    int hkey = hashCodeProduto(code_produto);
    char pkey1[3];
    char pkey2[3];
    pkey1[0] = code_produto[0];
    pkey1[1] = code_produto[1];
    pkey1[2] = '\0';
    pkey2[2] = '\0';

	if (table[hkey] == NULL)
		return 0;

	Produto it = table[hkey];

	while (it != NULL) {
        pkey2[0] = it->Codigo_Produto[0];
        pkey2[1] = it->Codigo_Produto[1];
		if (strcmp(pkey1, pkey2) == 0)
			return 1;
		it = it->prox;
	}

	return 0;

}

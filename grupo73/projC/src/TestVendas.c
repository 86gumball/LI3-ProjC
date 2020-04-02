#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AuxVendas.h"
#include "../include/produtoUtil.h"
#include "../include/clientesUtil.h"
#include "../include/stringUtils.h"

// Confirmado que funciona
int cliente_Existe (CBTS *tree, char code_cliente[]) {
    // produto key
	int pkey = code_cliente[0] - 'A';
    // hkey = key na hashtable
    short hkey = stoi(code_cliente);

	if (tree[pkey] == NULL)
		return 0;

	CBTS *it = &tree[pkey];

	while (*it != NULL) {
		if (hkey == (*it)->numero_identificacao)
			return 1;
		
		else if (hkey > (*it)->numero_identificacao)
			it = &(*it)->maior;

		else 
			it = &(*it)->menor;
	}

	return 0;
}

// Confirmado que funciona
int produto_Existe (PBST **table, char code_produto[]) {
  

	int pkey1 = code_produto[0] - 'A';
	int pkey2 = code_produto[1] - 'A';

	int hkey = stoi(code_produto);

	if (table[pkey1][pkey2] == NULL)
		return 0;

	PBST *it = &table[pkey1][pkey2];

	while (*it != NULL) {
		if (hkey == (*it)->numero_identificacao)
			return 1;
		
		else if (hkey > (*it)->numero_identificacao)
			it = &(*it)->maior;

		else 
			it = &(*it)->menor;
	}
	return 0;

}

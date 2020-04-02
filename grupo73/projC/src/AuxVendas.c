#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AuxVendas.h"

#define HashTableVenda Venda*

// TODO: Implement this
int hashCodeVenda(void){
    //int key = stoi(code_cliente + 1);
    //key = key % 4001;
    return 0;
}

// TODO: Implement this
Venda createVenda(Venda next,
                  char code_produto[],
                  char compra,
                  char code_cliente[],
                  unsigned int codigoPUM,
                  char filial){
    return NULL;
}

Venda cloneVenda(Venda outra){
    if (outra == NULL) {
        return NULL;
    }
    Venda new = malloc(sizeof(Venda));
    strcpy(new->code_produto, outra->code_produto);
    new->compra = outra->compra;
    strcpy(new->code_cliente, outra->code_cliente);
    new->codigoPUM = outra->codigoPUM;
    new->filial = outra->filial;
    new->prox = cloneVenda(outra->prox);
    return new;
}

// Cria um codigo PUM a partir de um preço, unidades e mes
unsigned int createPUM (float preco, int unidades, int mes) {
	int codigo_preco = preco * 100;
	int codigo_unidades = unidades * 100000;
	int codigo_mes = mes * 100000000;
	unsigned int codigo = codigo_mes + codigo_unidades + codigo_preco;
	return codigo;
}

float devolve_Preco (unsigned int codigoPUM) {
	float preco = codigoPUM % 100000;
	preco /= 100;
	return preco;
}

int devolve_unidades (unsigned int codigoPUM) {
	int unidades = codigoPUM % 100000000;
	unidades = unidades / 100000;
	return unidades;
}

int devolve_mes (unsigned int codigoPUM) {
	int mes = codigoPUM / 100000000;
	return mes;
}

// TODO: Fix this
// TODO: Make a seperate hashCode funtion that replaces the delimited code
void placeVenda (Venda p, HashTableVenda tableVen) {
    // Starting here
	int hkey = 0;
	int exp = 100;
	for (int i = 3; i < 6; i++) {
		hkey += exp * (p->code_produto[i] - '0');
		exp /= 10;
	}
	exp = 100000;
	for (int i = 1; i < 5; i++) {
		hkey += exp * (p->code_cliente[i] - '0');
		exp /= 10;
	}
    // Ending here

    // hkey tem a posicao na hashtable

    Venda new = cloneVenda(p);
    Venda it = tableVen[hkey];
    if (it == NULL) {
        tableVen[hkey] = new;
    } else {
        while (it->prox != NULL)
            it = it->prox;
        it->prox = new;
    }
}

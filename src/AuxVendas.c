#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AuxVendas.h"

void copialimitada(char a[], char b[] , int n) {
	int i;
	for (i = 0; i < n; i++)
		a[i] = b[i];
	a[i] = 0;
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

void placeVenda (Venda p, Venda *mem[]) {
	int local = 0;
	int i;
	int exp = 100;
	for (i = 3; i < 6; i++) {
		local += exp * (p.code_produto[i] - '0');
		exp /= 10;
	}
	exp = 100000;
	for (i = 1; i < 5; i++) {
		local += exp * (p.code_cliente[i] - '0');
		exp /= 10;
	}
	createVenda(p,mem[local%4001000]);
}

void createVenda(Venda p, Venda *mem) {
	Venda *it;
	it = mem;
	if (it != NULL)
		it = &(*it->prox);
	Venda *f = malloc(sizeof(Venda));
	strcpy(p.code_cliente,(*f).code_cliente);
	strcpy(p.code_produto,(*f).code_produto);
	(*f).prox = NULL;
	(*f).compra = p.compra;
	(*f).filial = p.filial;
	(*f).codigoPUM = p.codigoPUM;
	*it = *f;
}

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

int main (void) {

	FILE *f = fopen("Dados Iniciais/Vendas_1M.txt","r");

	Produto *memP = testProds();
	Cliente *memC = testClientes();

	Cliente *it;

	for (int i = 0; i < 4001; i++) {
		printf("%d:",i);
		for(it = &memC[i]; *it != NULL; it = &(*it)->prox)
			printf("%s->",(*it)->Codigo_Cliente);
		putchar(10);
	}	

	Venda **memV = malloc(4001000 * sizeof(Venda));

	Venda p;

	char *meses[] = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

	int lines = 0;
	float preco;
	int unidades;
	int mes;

	while (fscanf(f,"%s %f %d %c %s %d %c",p.produto, &preco, &unidades, &p.compra, p.cliente, &mes, &p.filial) != EOF) {
		p.codigo_Extra = codigo_Tudo (preco, unidades, mes);
		if (produto_Existe(memP,p.produto) && cliente_Existe(memC,p.cliente)) {
			//placeVenda(p,memV);
			lines++;
		}
	}
	
	preco = devolve_Preco(p.codigo_Extra);
	unidades = devolve_unidades(p.codigo_Extra);
	mes = devolve_mes(p.codigo_Extra);


	printf("%d das vendas são verdadeiras.\n", lines);
	printf("Produto:%s\n", p.produto);

	printf("Preço:%f\n", preco);
	printf("Unidades:%d\n", unidades);

	if (p.compra == 'P')
		printf("Por Promoção\n");
	else printf("Compra Normal\n");
	printf ("Cliente:%s\n",p.cliente);

	printf ("Mes:%s\n", meses[mes - 1]);

	printf ("Filial:%c\n", p.filial);

	fclose(f);
	
	return 0;
}

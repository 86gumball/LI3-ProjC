#include <stdio.h>
#include <stdlib.h>
#include "../include/TestProdutos.h"
#include "../include/TestClientes.h"
#include "../include/AuxVendas.h"
#include "../include/TestVendas.h"

#define pathToVendas "../Dados Iniciais/Vendas_1M.txt"

int main(void){
    FILE *f = fopen(pathToVendas, "r");

    Produto *memP = testProds();
    Cliente *memC = testClientes();
    printf("senpai notice me\n");

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

#include <stdio.h>
#include <stdlib.h>
#include "../include/TestProdutos.h"
#include "../include/TestClientes.h"
#include "../include/AuxVendas.h"
#include "../include/TestVendas.h"

#define pathToVendas "../Dados Iniciais/Vendas_1M.txt"
#define HashTableProduto Produto*
#define HashTableCliente Cliente*
#define HashTableVenda Venda*

// TODO: Rename TestProdutos -> produtosUtils
// TODO: Rename TestClientes -> clientesUtils
int main(void){
    FILE *f = fopen(pathToVendas, "r");

    // Cria uma hashtable e enche-a com todos os produtos
    HashTableProduto tablePro = testProds();
    // Cria uma hashtable e enche-a com todos os clientes
    HashTableCliente tableCli = testClientes();

    // Start debugging only 
    /*
    Produto it;
    for (int i = 0; i < 9000; i++) {
        printf("%d:",i);
        for(it = tablePro[i]; it != NULL; it = it->prox)
            printf("%s->",it->Codigo_Produto);
        putchar(10);
    }
    */
    // End debugging only

    // tam = nº clientes * nº produtos
    // tam = 4001 * 1000
    int tam = 4001000;
    HashTableVenda tableVen = malloc(tam * sizeof(Venda));

    Venda p = malloc(sizeof(struct venda));;

    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    int lines = 0;
    float preco;
    int unidades;
    int mes;

    // Preenche Vendas e as variaveis definidas a cima
    while (fscanf(f,"%s %f %d %c %s %d %c", p->code_produto,
                                            &preco,
                                            &unidades,
                                            &p->compra,
                                            p->code_cliente,
                                            &mes,
                                            &p->filial) != EOF) {
        // Converte preco, unidades e mes num codigoPUM
        p->codigoPUM = createPUM(preco, unidades, mes);
        if (produto_Existe(tablePro, p->code_produto) && cliente_Existe(tableCli, p->code_cliente)) {
            //placeVenda(p, tableVen);
            lines++;
        }
    }
    
    // Start debugging only 
    /*
    Produto it;
    for (int i = 0; i < 9000; i++) {
        printf("%d:",i);
        for(it = tablePro[i]; it != NULL; it = it->prox)
            printf("%s->",it->Codigo_Produto);
        putchar(10);
    }
    */
    // End debugging only



    preco = devolve_Preco(p->codigoPUM);
    unidades = devolve_unidades(p->codigoPUM);
    mes = devolve_mes(p->codigoPUM);


    printf("%d das vendas são verdadeiras.\n", lines);
    printf("Produto:%s\n", p->code_produto);

    printf("Preço:%f\n", preco);
    printf("Unidades:%d\n", unidades);

    if (p->compra == 'P')
        printf("Por Promoção\n");
    else printf("Compra Normal\n");
    printf ("Cliente:%s\n",p->code_cliente);

    printf ("Mes:%s\n", meses[mes - 1]);

    printf ("Filial:%c\n", p->filial);

    fclose(f);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "../include/stringUtils.h"
#include "../include/produtoUtil.h"

PBST creatreNodeProduto (char key[], short numero) {
    PBST new = (PBST) malloc(sizeof(struct produtoBST));
    
    new->code_produto_upper = key[0];
    new->code_produto_sub = key[1];
    //new->heigth = 1; 
    new->numero_identificacao = numero;
    new->maior = NULL;
    new->menor = NULL;

    return new;
}

/*
short height (CBTS tree) {
    if (tree == NULL)
        return 0;

    return tree->heigth;
}

int maxHeight (short tamanho_maior, short tamanho_menor) {
    
    if(tamanho_maior > tamanho_menor)
        return tamanho_maior;
    else
        return tamanho_menor;    
}


int BalanceFactor (CBTS tree) {
    
    return height(tree->maior) - height(tree->menor);
}

CBTS rotacaoMenor (struct clienteBTS *tree) {
    struct clienteBTS *mem = tree->menor;
    struct clienteBTS *guarda = mem->maior;

    mem->maior = tree;
    tree->menor = guarda;

    tree->heigth = maxHeight(height(tree->maior),     
                             height(tree->menor)) + 1;  
    mem->heigth = maxHeight(height(mem->maior),  
                             height(mem->menor)) + 1;  

    return mem;
}

CBTS rotacaoMaior (struct clienteBTS *tree) {
    struct clienteBTS *mem = tree->maior;
    struct clienteBTS *it = mem->menor;

    mem->menor = tree;
    tree->maior = it;

    tree->heigth = maxHeight(height(tree->maior),     
                             height(tree->menor)) + 1;  
    mem->heigth = maxHeight(height(mem->maior),  
                            height(mem->menor)) + 1;  

    return mem;
}
*/

PBST insertP (char buffer[], struct produtoBST *tree, short key_num) {
    
    if (tree == NULL){
        tree = creatreNodeProduto (buffer, key_num);
        return tree;
    }
    else {
        if (tree->numero_identificacao == key_num)
            return tree;

        else if (tree->numero_identificacao > key_num)
            tree->menor = insertP (buffer, (tree->menor), key_num);

        else
            tree->maior = insertP (buffer, (tree->maior), key_num);            
    }

//TODO: Conseguir implementar a rotações de AVL para melhorar eficiencia
/*
    tree ->heigth = maxHeight (height(tree->maior), height(tree->menor)) + 1;

    int balance_factor = BalanceFactor(tree);

    if (balance_factor == 2) {
        
        if (BalanceFactor(tree->maior) == 1)
            tree = rotacaoMaior (tree);
    
        else {
            //rotacaoMenor (tree->maior);
            tree = rotacaoMaior (tree);
        }
    }

    else if (balance_factor == -2) {

        if (BalanceFactor (tree->menor) == -1)
            return rotacaoMenor (tree);

        else {
            //tree->menor = rotacaoMaior (tree->menor);
            return rotacaoMenor (tree);
        }
    }
*/
    return tree;

};

void chooseTreeP (char key[], PBST *mem[], short posTable) {
    int key1 = key[0] - 'A';
    int key2 = key[1] - 'A';
    PBST *it = &mem[key1][key2];
    *it = insertP (key,*it, posTable);
}

PBST **catalogoProdutos (PBST **mem) {
    FILE *f = fopen("/home/tripz/Desktop/LI3/LI3/Dados Iniciais/Produtos.txt", "r");
    
    for (int j = 0; j < 26; j++){
        for (int i = 0; i < 26; i++)
            mem[i][j] = NULL;
    }

    char buffer[10];
    short valor_doBuffer;
    char key[2];

    while (fgets(buffer,10,f)) {
        valor_doBuffer = stoi(buffer);
        key[0] = buffer[0];
        key[1] = buffer[1];
        chooseTreeP(key, mem, valor_doBuffer);
    };

    fclose(f);

    return mem;
}
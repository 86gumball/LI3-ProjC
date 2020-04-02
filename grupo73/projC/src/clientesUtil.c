#include <stdio.h>
#include <stdlib.h>
#include "../include/stringUtils.h"
#include "../include/clientesUtil.h"

CBTS creatreNodeCliente (char key, short numero) {
    CBTS new = (CBTS) malloc(sizeof(struct clienteBTS));
    
    new->code_cliente = key;
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

CBTS insert (char buffer, struct clienteBTS *tree, short key_num) {
    
    if (tree == NULL)
        return creatreNodeCliente (buffer, key_num);
    
    else {
        if (tree->numero_identificacao == key_num)
            return tree;

        else if (tree->numero_identificacao > key_num)
            tree->menor = insert (buffer, (tree->menor), key_num);

        else
            tree->maior = insert (buffer, (tree->maior), key_num);            
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

void chooseTree (char key, CBTS mem[], short posTable) {
    CBTS *it = mem + (key-'A');

    *it = insert (key,*it, posTable);
}

CBTS *catalogoClientes (CBTS *mem) {
    FILE *f = fopen("/home/tripz/Desktop/LI3/LI3/Dados Iniciais/Clientes.txt", "r");
    
    for (int i = 0; i < 26; i++)
        mem[i] = NULL;

    char buffer[10];
    short valor_doBuffer;

    while (fgets(buffer,10,f)) {
        valor_doBuffer = stoi(buffer);
        chooseTree(buffer[0], mem, valor_doBuffer);
    };
    fclose(f);

    return mem;
}
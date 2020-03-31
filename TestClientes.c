#include <stdio.h>
#include <stdlib.h>
#include "TestClientes.h"


Cliente createCliente (Cliente *it, char key[]) {
	//Alocação de memoria
	Cliente new = (Cliente) malloc (sizeof (struct cliente)); 
	//Passar para o inicio da lista ligada
	new->prox = *it; 
	
	// Iteração pela String
	for (int i = 0; i < 5; i++) 
		// Passagem de caracteres do codigo para o corpo
		new->Codigo_Cliente[i] = key[i]; 

	// Retorna o novo corpo
	return new; 
}

void iterate (int posTable, Cliente mem[], char key[], char pos) {
	//Uso de um iterador na posição suposta
	Cliente *it = &mem[posTable%4001];

	//Verificação se não existe codigo repetido
	//(ex: codigo 'A'3960, se pos == 'A', quer dizer que o codigo está repetido)
	while (*it != NULL && (*it)->Codigo_Cliente[0] != pos) 
		//Iteração pela lista
		it = &(*it)->prox; 

	//Verificação que chegou ao fim da lista e é permitido alocar o novo codigo
	if (*it == NULL) 
		//Criação do novo cliente no final da lista
		*it = createCliente (it, key); 

}

void allocate (char key[], Cliente mem[]) {
	//Caracter que vai ser usado para determinar se é repetido ou não
	char pos = key[0];
	//Posição na tabela 
	int posTable = 0;
	//Expoente para o codigo 
	int exp = 1000; 

	//Leitura do codigo (ex:A'3''9''6''0')
	for (int i = 1; i != '\r' && i != '\n'; i++) {
		//Transformação porção do codigo em numeros 
		posTable += (key[i]-'0') * exp; 
		exp /= 10; 
	}
	
	//Verificação da existência do codigo
	iterate (posTable, mem, key, pos);  
}

Cliente* testClientes (void) {
	//Abertura do ficheiro
	FILE *f = fopen ("Dados Iniciais/Clientes.txt","r");
	
	//Alocação de memória para guardares tudo
	Cliente *mem = malloc(4001 * sizeof(Cliente));

	//Buffer para guardar a String do codigo
	char buf[10];

	//Renovar as strings no buffer até ao fim do ficheiro
	while (fgets(buf,10,f))
		
		allocate(buf,mem);
	
	fclose(f);

	return mem;
}



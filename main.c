#include <stdio.h>

void putString(char *output, char *first, char *second)
{
	int i,j;
	for (i = 0; first[i] != 0; i++)
		output[i] = first[i];

	for (j = 0; second[j] != 0; j++, i++)
		output[i] = second[j]; 

	output[i] = 0;
}

int main(void){

	printf("Escolha um tipo de ficheiro: ");
	char file[255];
	char name[255];
	scanf ("%s",name);

	putString(file,"Dados Iniciais/", name);
	putString(file,file,".txt");
   
	FILE *filePointer = fopen(file,"r");

	int lines = 0;
	char holdChar;
	int sizeOfWords;

	for (sizeOfWords = 0, holdChar = fgetc(filePointer); holdChar != 13; holdChar = fgetc(filePointer), sizeOfWords++);
	
	lines ++;

	for (holdChar = fgetc(filePointer); holdChar != EOF; holdChar = fgetc(filePointer))
		if (holdChar == 13)
			lines++;

	printf("Words Size:%d\nNumber Of Lines:%d\n",sizeOfWords,lines);

	fseek(filePointer,0 , SEEK_SET);

	char clientes[lines*sizeOfWords];

	int caracter = 0;

	for (holdChar = fgetc(filePointer); holdChar != EOF; holdChar = fgetc(filePointer))
	{
		if (holdChar != 10 && holdChar != 13)
		{
			clientes[caracter] = holdChar;
			caracter++;
		}
	}

	int escolha;

	printf("Escolha os dados do %s (<=%d): ", name ,lines);

	scanf("%d", &escolha);

	while (escolha > lines || escolha <= 0)
	{
		printf("Erro, escolha um %s entre 1 e %d: ", name , lines);
		scanf("%d",&escolha);
	}

	printf("%s nº %d: ", name , escolha);

	for (int i = 0; i < sizeOfWords; i++)
		putchar(clientes[(escolha-1)*sizeOfWords+i]);
	putchar(10);

	fclose(filePointer);

	//Isto ainda é um teste, separar em funções para minimizar o codigo, documentar no final, e intercetar o que os valores fazem

    return 0;
}

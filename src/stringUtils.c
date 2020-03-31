#include <string.h>

// Requires: 1000 <= num <= 9999
int stoi(char num[]){
    int converted = 0;
    int exp = 1000;
	for (int i = 0; i < 4; i++) {
		//Adição de dos numeros usando o expoente (ex:'3'*1000+'2'*100+'1'*10+'0'*1)
		converted += (num[i] - '0') * exp;
        exp /= 10;
	}
    return converted;
}

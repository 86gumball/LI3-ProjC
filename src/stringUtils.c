#include <string.h>

//Nota: short utiliza 2 bytes e range [-32,478..32,477], acaba por usar menos memoria
// Requires: a string that ends with \0
short stoi (char num[]) {
    int ret = 0;
    int i = 0;

    while (!('0' <= num[i] && num[i] <= '9'))
        i++;

    while ('0' <= num[i] && num[i] <= '9') {
        ret *= 10;
        ret += num[i] - '0';
        i++;
    }

    return ret;
}

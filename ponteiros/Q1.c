#include <stdio.h>

int main(){
    int x = 10;
    int *p = &x;

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Valor armazenado em p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}
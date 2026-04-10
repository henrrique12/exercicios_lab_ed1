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

/* LÓGICA:
 * Para esse código, declarei uma variável inteira e um ponteiro que aponta para o endereço dela. 
 * No 'printf', comparei o valor da variável com o valor apontado pelo ponteiro (*p) 
 * e mostrei que o endereço de 'x' é exatamente o valor guardado dentro de 'p'.
 */
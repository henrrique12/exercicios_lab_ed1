#include <stdio.h>

int main(){
    int v [5] = {1,2,3,4,5};
    int *p = v;
    
    for (int i = 0; i < 5; i++){
    printf("%d ", *(p+i));
    }

    return 0;
}

/* LÓGICA:
 * Como o nome de um vetor já aponta para o seu primeiro elemento, atribuí 'v' ao ponteiro 'p'. 
 * Usei um laço 'for' e aritmética de ponteiros '*(p+i)' para percorrer cada posição da memória 
 * e imprimir os elementos, em vez de usar os colchetes tradicionais.
 */
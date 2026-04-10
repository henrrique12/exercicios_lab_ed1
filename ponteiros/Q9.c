#include <stdio.h>

int main() {
    int x = 10;     
    int *p = &x;     
    int **pp = &p;   

    printf("Valor de x: %d\n", x);      
    printf("Valor de *p: %d\n", *p);   
    printf("Valor de **pp: %d\n", **pp); 

    return 0;
}

/* LÓGICA:
 * Fiz o ponteiro 'p' apontar para 'x', e o ponteiro 'pp' apontar para o endereço de 'p'. 
 * No final, mostrei como é possível chegar ao valor original de 'x' "mergulhando" 
 * dois níveis na memória através da dupla desreferenciação.
 */
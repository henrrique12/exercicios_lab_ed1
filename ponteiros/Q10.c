#include <stdio.h>

void inverter(int *v, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = *(v+i);                  
        *(v+i) = *(v+(n-1-i));              
        *(v+(n-1-i)) = temp;               
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    inverter(v, n); 

    printf("\nVetor invertido: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

/* LÓGICA:
 * O laço 'for' percorre apenas até a metade do vetor (n/2), trocando o elemento da posição atual *(v+i) 
 * com o seu correspondente no final do array *(v+(n-1-i)). 
 * Usei uma variável 'temp' para garantir que os valores não se perdessem durante a troca de posições.
 */
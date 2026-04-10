#include <stdio.h>

int somaVetor (int *v , int n ) {
    int soma = 0;

    for(int i = 0; i < n; i++){
        soma += *(v + i);
    }
    return soma;
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    
    int resultado = somaVetor(v, 5);

    printf("A soma dos elementos do vetor é: %d\n", resultado);

    return 0;
}

/* LÓGICA:
 * Usei um acumulador chamado 'soma' iniciado em zero e um laço que percorre o vetor usando o deslocamento do ponteiro. 
 * A cada iteração, o valor contido no endereço atual é somado ao total, que é retornado ao final.
 */
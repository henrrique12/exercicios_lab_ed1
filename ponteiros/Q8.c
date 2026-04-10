#include <stdio.h>

int maiorElemento(int *v, int n) {
    int maior = *v; 
    for (int i = 1; i < n; i++) {
        if (*(v+i) > maior) {
            maior = *(v+i); 
        }
    }
    return maior;
}

int main() {
    int v[5] = {3, 7, 2, 9, 5};
    int resultado = maiorElemento(v, 5);

    printf("O maior elemento do vetor é: %d\n", resultado);

    return 0;
}

/* LÓGICA:
 * Para encontrar o maior valor em um conjunto, passei o vetor para a função e assumi que o primeiro elemento (*v) era o maior. 
 * Depois, percorri o restante do vetor comparando o valor atual *(v+i) com o valor guardado na variável 'maior'. 
 * Se encontrasse um número superior, atualizava a variável.
 */
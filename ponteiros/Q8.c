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

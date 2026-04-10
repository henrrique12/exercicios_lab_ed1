#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    printf("vetor invertido: ");
    for (int i = n - 1; i >= 0; i--){
        printf("%d", vetor[i]);
    }

    free(vetor);
    return 0;
}

/* LÓGICA:
 * Primeiro, perguntei o tamanho e usei o 'malloc' para "reservar um espaço" exato no computador.
 * Depois de guardar os números, e usei o laço 'for' para mostrar invertido:
 * em vez de começar do primeiro, ele começa do último.
 * No fim, usei o 'free' para limpar a memória.
 */
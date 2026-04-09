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
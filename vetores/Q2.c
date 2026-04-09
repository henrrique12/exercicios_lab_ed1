#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;

    printf("Linhas: ");
    scanf("%d", &l);
    printf("Colunas: ");
    scanf("%d", &c);

    int **matriz = (int **) malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) {
        matriz[i] = (int *) malloc(c * sizeof(int));
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta:\n");
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < l; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
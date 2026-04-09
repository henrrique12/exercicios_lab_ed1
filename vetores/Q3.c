#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    int **matriz = (int **) malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++){
        matriz[i] = (int *) malloc(n * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
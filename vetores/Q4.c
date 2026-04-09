#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int p;

    printf("Quantidade de pessoas: ");
    scanf("%d", &p);
    getchar();

    int *idades = (int *) malloc(p * sizeof(int));

    char **nomes = (char **) malloc(p * sizeof(char *));

    for (int i = 0; i < p; i++){
        nomes[i] = (char *) malloc( 100 * sizeof(char));
    }

    for (int i = 0; i < p; i++){

        printf("Nome completo: ");
        fgets(nomes[i], 100, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &idades[i]);
        getchar();
    }

    printf("\nMostrar nomes cadastrados:\n");

    for (int i = 0; i < p; i++){
        printf("%s\n", nomes[i]);
    }

    for (int i = 0; i < p; i++){
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
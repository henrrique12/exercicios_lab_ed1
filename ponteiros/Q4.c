#include <stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n1, n2;

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    troca(&n1, &n2);

    printf("Depois da troca:\n");
    printf("Primeiro número: %d\n", n1);
    printf("Segundo número: %d\n", n2);

    return 0;
}

/* LÓGICA:
 * Para trocar dois valores, usei ponteiros para conseguir alterar as variáveis originais da 'main'. 
 * Utilizei uma variável auxiliar chamada 'temp' para guardar temporariamente o valor do primeiro endereço, 
 * permitindo que a troca ocorresse sem que nenhum dado fosse sobrescrito e perdido durante o processo.
 */
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
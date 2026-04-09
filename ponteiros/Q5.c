#include <stdio.h>

int maior (int *a , int * b ) {
    if(*a > *b){
        return *a;
    } else{
        return *b;
    }
}

int main(){
    int n1, n2, resultado;

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);
    
    resultado = maior(&n1, &n2);

    printf("O maior número é: %d",resultado);

    return 0;
}
#include <stdio.h>

void soma(int *a, int *b, int *resultado){
    *resultado = *a + *b;
}

int main(){
    int n1, n2, resultado;
    
    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    soma(&n1, &n2, &resultado);

    printf("a soma é: %d", resultado);

    return 0;
}

/* LÓGICA:
 * Criei uma função 'soma' que não retorna nada (void), mas recebe os endereços de memória das variáveis. 
 * Dentro da função, o resultado da conta é armazenado diretamente no endereço da variável 'resultado' da 'main', 
 * permitindo que o valor persista fora da função.
 */
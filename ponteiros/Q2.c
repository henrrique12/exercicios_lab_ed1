#include <stdio.h>

int main(){
    int n = 5;
    int *p = &n;

    *p = 20;

    printf("Novo valor de n: %d", n);

    return 0;
}

/* LÓGICA:
 * Nesse exercício, criei um ponteiro para a variável 'n' e, em vez de mudar o valor de 'n' diretamente, 
 * usei o operador de desreferenciação (*p) para atribuir um novo valor. 
 * Isso prova que, ao alterar o conteúdo do endereço, a variável original também é atualizada.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char documento[30];
    int idade;
} Pessoa;

void preencherPessoa(Pessoa *p) {
    printf("Nome: ");
    fgets(p->nome, 100, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Documento: ");
    fgets(p->documento, 30, stdin);
    p->documento[strcspn(p->documento, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &p->idade);
    getchar();
}

void imprimirPessoa(const Pessoa *p) {
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d\n", p->idade);
}

void atualizarIdade(Pessoa *p, int novaIdade) {
    p->idade = novaIdade;
}

void maisVelhaMaisNova(Pessoa *vet, int n) {
    if (n <= 0) return;

    int iVelha = 0, iNova = 0;
    for (int i = 1; i < n; i++) {
        if (vet[i].idade > vet[iVelha].idade) iVelha = i;
        if (vet[i].idade < vet[iNova].idade) iNova = i;
    }

    printf("\nPessoa mais velha:\n");
    printf("Nome: %s | Idade: %d\n", vet[iVelha].nome, vet[iVelha].idade);

    printf("\nPessoa mais nova:\n");
    printf("Nome: %s | Idade: %d\n", vet[iNova].nome, vet[iNova].idade);
}

int main() {
    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    Pessoa *vet = (Pessoa *) malloc(n * sizeof(Pessoa));
    if (vet == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nCadastro da pessoa %d:\n", i + 1);
        preencherPessoa(&vet[i]);
    }

    for (int i = 0; i < n; i++) {
        imprimirPessoa(&vet[i]);
    }

    maisVelhaMaisNova(vet, n);

    free(vet);
    return 0;
}

/*LÓGICA:
 * Para esse código, a minha ideia foi organizar os dados de cada pessoa dentro de uma 'struct'. 
 * Como eu não sabia quantas pessoas seriam cadastradas, usei 'malloc' para criar o vetor dinamicamente.
 * Na parte da leitura, usei um laço de repetição para comparar as idades 
 * e encontrar a pessoa mais velha e a mais nova. Terminei o código liberando a memória com 'free', 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float salario;
    int id;
    char cargo[50];
} Funcionario;

void preencherFuncionario(Funcionario *f) {
    printf("Nome: ");
    fgets(f->nome, 100, stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';

    printf("Cargo: ");
    fgets(f->cargo, 50, stdin);
    f->cargo[strcspn(f->cargo, "\n")] = '\0';

    printf("Identificador: ");
    scanf("%d", &f->id);

    printf("Salário: ");
    scanf("%f", &f->salario);
    getchar(); 
}

void imprimirFuncionario(const Funcionario *f) {
    printf("\n--- Dados do Funcionário ---\n");
    printf("Nome: %s\n", f->nome);
    printf("Cargo: %s\n", f->cargo);
    printf("ID: %d\n", f->id);
    printf("Salário: %.2f\n", f->salario);
}

void alterarSalario(Funcionario *f, float novoSalario) {
    f->salario = novoSalario;
}

void maiorMenorSalario(Funcionario *vet, int n) {
    if (n <= 0) return;

    int iMaior = 0, iMenor = 0;
    for (int i = 1; i < n; i++) {
        if (vet[i].salario > vet[iMaior].salario) iMaior = i;
        if (vet[i].salario < vet[iMenor].salario) iMenor = i;
    }

    printf("\nFuncionário com maior salário:\n");
    printf("Nome: %s | Cargo: %s | Salário: %.2f\n", vet[iMaior].nome, vet[iMaior].cargo, vet[iMaior].salario);

    printf("\nFuncionário com menor salário:\n");
    printf("Nome: %s | Cargo: %s | Salário: %.2f\n", vet[iMenor].nome, vet[iMenor].cargo, vet[iMenor].salario);
}

int main() {
    int n;
    printf("Quantos funcionários deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    Funcionario *vet = (Funcionario *) malloc(n * sizeof(Funcionario));
    if (vet == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nCadastro do funcionário %d:\n", i + 1);
        preencherFuncionario(&vet[i]);
    }

    for (int i = 0; i < n; i++) {
        imprimirFuncionario(&vet[i]);
    }

    maiorMenorSalario(vet, n);

    free(vet);
    return 0;
}

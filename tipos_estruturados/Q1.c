#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 5
#define MAX_VAGAS 4

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char id) {
    Turma* t = (Turma*) malloc(sizeof(Turma));
    if (t == NULL) return NULL;
    t->id = id;
    t->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++) {
        t->alunos[i] = NULL;
    }
    return t;
}

void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas == 0) {
        printf("Turma sem vagas!\n");
        return;
    }

    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            turma->alunos[i] = (Aluno*) malloc(sizeof(Aluno));
            turma->alunos[i]->mat = mat;
            strcpy(turma->alunos[i]->nome, nome);
            for (int j = 0; j < 3; j++) turma->alunos[i]->notas[j] = 0;
            turma->alunos[i]->media = 0;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!\n");
            return;
        }
    }
}

void lancar_notas(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("\nMatricula: %d\nAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            float soma = 0;
            for (int j = 0; j < 3; j++) {
                printf("Digite a nota %d: ", j+1);
                scanf("%f", &turma->alunos[i]->notas[j]);
                soma += turma->alunos[i]->notas[j];
            }
            turma->alunos[i]->media = soma / 3;
        }
    }
}

void imprime_alunos(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("\nMatricula: %d\nNome: %s\nMedia: %.2f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
    }
}

Turma* procurar_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i]->id == id) return turmas[i];
    }
    return NULL;
}

int main() {
    Turma* turmas[MAX_TURMAS];
    int nTurmas = 0;
    int op;

    printf("Bem vindo ao programa de gerenciamento de turmas!\n");

    do {
        printf("\nMenu:\n");
        printf("1 - Criar turma\n");
        printf("2 - Listar turmas\n");
        printf("3 - Matricular aluno\n");
        printf("4 - Lançar notas\n");
        printf("5 - Listar alunos\n");
        printf("6 - Sair\n");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            if (nTurmas >= MAX_TURMAS) {
                printf("Número máximo de turmas atingido!\n");
            } else {
                char id;
                printf("Digite um id: ");
                scanf(" %c", &id);
                turmas[nTurmas] = cria_turma(id);
                if (turmas[nTurmas] != NULL) {
                    printf("Turma %c criada com sucesso!\n", id);
                    nTurmas++;
                }
            }
        } else if (op == 2) {
            imprime_turmas(turmas, nTurmas);
        } else if (op == 3) {
            char id;
            int mat;
            char nome[81];
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            getchar();
            Turma* t = procurar_turma(turmas, nTurmas, id);
            if (t == NULL) {
                printf("Turma inexistente!\n");
            } else {
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                getchar();
                printf("Digite o nome: ");
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                matricula_aluno(t, mat, nome);
            }
        } else if (op == 4) {
            char id;
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma* t = procurar_turma(turmas, nTurmas, id);
            if (t == NULL) {
                printf("Turma inexistente!\n");
            } else {
                lancar_notas(t);
            }
        } else if (op == 5) {
            char id;
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma* t = procurar_turma(turmas, nTurmas, id);
            if (t == NULL) {
                printf("Turma inexistente!\n");
            } else {
                imprime_alunos(t);
            }
        }
    } while (op != 6);

    printf("Obrigado por usar este programa!\n");

    for (int i = 0; i < nTurmas; i++) {
        for (int j = 0; j < MAX_VAGAS; j++) {
            if (turmas[i]->alunos[j] != NULL) {
                free(turmas[i]->alunos[j]);
            }
        }
        free(turmas[i]);
    }

    return 0;
}

/* LÓGICA:
 * Neste sistema, utilizei 'structs' e 'typedef' para organizar os dados de Alunos e Turmas de forma hierárquica. 
 * A estrutura principal utiliza um vetor de ponteiros para Turmas, onde cada Turma possui seu próprio vetor de ponteiros para Alunos.
 * Apliquei alocação dinâmica com 'malloc' em dois níveis: primeiro para criar a Turma e, posteriormente, 
 * para cada Aluno que é matriculado, garantindo que a memória seja usada apenas quando necessário.
 * Implementei funções de busca para localizar turmas por ID e lógica de controle de vagas para evitar matrículas excedentes.
 * e no final usei o free para liberar toda a memória alocada.
 */
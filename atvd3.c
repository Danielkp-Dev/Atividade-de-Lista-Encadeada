#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

int buscarCidadao(struct No *head, int cpf_buscado) {
    struct No *atual = head;

    while (atual != NULL) {
        if (atual->dado == cpf_buscado) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

int main() {
    // Criando nós manualmente
    struct No *n1 = malloc(sizeof(struct No));
    struct No *n2 = malloc(sizeof(struct No));
    struct No *n3 = malloc(sizeof(struct No));

    n1->dado = 111;
    n2->dado = 222;
    n3->dado = 333;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = NULL;

    int cpf = 222;

    if (buscarCidadao(n1, cpf)) {
        printf("CPF encontrado!\n");
    } else {
        printf("CPF nao encontrado!\n");
    }

    // Liberando memória
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
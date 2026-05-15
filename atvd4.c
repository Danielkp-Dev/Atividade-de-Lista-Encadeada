#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

void inserirApos(struct No *head, int id_alvo, int novo_id) {
    struct No *atual = head;

    while (atual != NULL) {

        if (atual->dado == id_alvo) {

            struct No *novo = malloc(sizeof(struct No));

            novo->dado = novo_id;

            // Ordem correta
            novo->proximo = atual->proximo;
            atual->proximo = novo;

            return;
        }

        atual = atual->proximo;
    }

    printf("ID alvo nao encontrado.\n");
}

void imprimirLista(struct No *head) {
    struct No *atual = head;

    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main() {

    // Criando nós
    struct No *n1 = malloc(sizeof(struct No));
    struct No *n2 = malloc(sizeof(struct No));
    struct No *n3 = malloc(sizeof(struct No));

    n1->dado = 100;
    n2->dado = 500;
    n3->dado = 900;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = NULL;

    printf("Lista antes:\n");
    imprimirLista(n1);

    inserirApos(n1, 500, 777);

    printf("Lista depois:\n");
    imprimirLista(n1);

    return 0;
}
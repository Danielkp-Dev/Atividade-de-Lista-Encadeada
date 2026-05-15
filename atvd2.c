#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

// Função que conta os nós da lista
int contarFila(struct No *head) {
    int contador = 0;
    struct No *atual = head;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int main() {

    // Criando nós manualmente
    struct No *n1 = malloc(sizeof(struct No));
    struct No *n2 = malloc(sizeof(struct No));
    struct No *n3 = malloc(sizeof(struct No));

    // Valores
    n1->dado = 10;
    n2->dado = 20;
    n3->dado = 30;

    // Ligando os nós
    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = NULL;

    // Chamando a função
    int total = contarFila(n1);

    printf("Total de alunos na fila: %d\n", total);

    // Liberando memória
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
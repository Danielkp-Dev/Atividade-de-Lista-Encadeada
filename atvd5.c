#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

// Remove um CPF da lista
void removerCpf(struct No **head, int cpf_alvo) {

    struct No *atual = *head;
    struct No *anterior = NULL;

    // Procura o CPF na lista
    while (atual != NULL && atual->dado != cpf_alvo) {
        anterior = atual;
        atual = atual->proximo;
    }

    // CPF não encontrado
    if (atual == NULL) {
        printf("CPF nao encontrado.\n");
        return;
    }

    // Caso o nó seja o primeiro da lista
    if (anterior == NULL) {
        *head = atual->proximo;
    }
    else {
        // Faz o anterior pular o nó removido
        anterior->proximo = atual->proximo;
    }

    // Libera memória
    free(atual);

    printf("CPF removido com sucesso.\n");
}

// Imprime a lista
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
    struct No *n4 = malloc(sizeof(struct No));

    // Valores
    n1->dado = 111;
    n2->dado = 222;
    n3->dado = 333;
    n4->dado = 444;

    // Ligando lista
    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    n4->proximo = NULL;

    // Head da lista
    struct No *head = n1;

    printf("Lista antes:\n");
    imprimirLista(head);

    // Remove CPF
    removerCpf(&head, 333);

    printf("\nLista depois:\n");
    imprimirLista(head);

    // Liberando memória restante
    while (head != NULL) {
        struct No *temp = head;
        head = head->proximo;
        free(temp);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;             // Pode ser um CPF, Protocolo ou ID
    struct No *proximo;   // A corrente apontando para o próximo
};

void imprimirObras(struct No *head){
    // Usar outra variável para percorrer (não modifica a corrente principal)
    struct No *atual = head;
    printf(" === Protocolo de obras ===\n ");
    
    while(atual != NULL){
        printf("[Protocolo: %d] -> ", atual->dado);
        
        // indo para o proximo
        atual = atual->proximo;
    }
}

int main (){
    //Simulando criação de 3 obras
    struct No *obra1 = (struct No*) malloc(sizeof(struct No));
    struct No *obra2 = (struct No*) malloc(sizeof(struct No));
    struct No *obra3 = (struct No*) malloc(sizeof(struct No));

    //Inserindo valor (payload)
    obra1->dado = 1045;
    obra2->dado = 2088;
    obra3->dado = 3012;
    
    //Inserindo as correntes (proximo)
    obra1->proximo = obra2;
    obra2->proximo = obra3;
    obra3->proximo = NULL;
    
    //Inicio da lista
    struct No *inicio_da_lista = obra1;
    
    // Invocando chamada impressão
    imprimirObras(inicio_da_lista);
    
    //Boa pratica
    free(obra1);
    free(obra2);
    free(obra3);
    
    return 0;
}
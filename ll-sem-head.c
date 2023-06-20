#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int chave;
    struct NODE* prox;
}Node;

// GLOBAL
Node* primeiro_node;
Node* ptlista;
// -------

Node* inicializar(Node* no, int chave){
    no = (Node*) malloc(sizeof(Node));
    no->chave = chave;
    no->prox = NULL;

    if(!no){
        printf("deu ruim na alocacao");
    }

    return no;
}

void insere_chave(Node** ptlista, int chave){
    
    // malloca o novo node
    Node* novo = (Node*) malloc (sizeof(Node));
    novo->chave = chave;
    novo->prox = NULL;
    
    // checa se a lista está vazia ou se vai ser o primeiro node
    if(*ptlista == NULL || (*ptlista)->chave > chave){
        novo->prox = *ptlista;
        *ptlista = novo;
        return;
    }
    
    Node* atual = *ptlista;

    // acha onde vai inserir
    while(atual->prox != NULL && (atual->prox->chave < chave)){
        atual = atual->prox;
    }

    // conserta os ponteiros
    novo->prox = atual->prox;
    atual->prox = novo;
}

void remove_chave(Node** ptlista, int chave){
    Node* atual = *ptlista;
    
    if(atual->chave = chave){
        *ptlista = atual->prox;
        return;
    }

    while(atual->prox != NULL){
        if(atual->prox->chave = chave){
            atual->prox = atual->prox->prox;
        }
    }
}

void print_lista(Node* ptlista){
    Node* atual = ptlista;

    int i = 1;
    printf("\n");

    while(atual != NULL){

        printf("%d -> ", atual->chave);
        
        atual = atual->prox;
        i++;
    }
}


int main(){
    primeiro_node = inicializar(primeiro_node, 6);
    ptlista = primeiro_node;

    insere_chave(&ptlista, 14);
    insere_chave(&ptlista, 3);
    insere_chave(&ptlista, 15);
    insere_chave(&ptlista, 10);
    insere_chave(&ptlista, 5);
    insere_chave(&ptlista, 8);
    insere_chave(&ptlista, 31);
    insere_chave(&ptlista, 7);
    insere_chave(&ptlista, 43);
    insere_chave(&ptlista, 6);
    
    print_lista(ptlista);

    remove_chave(&ptlista, 5);
    remove_chave(&ptlista, 3);
    remove_chave(&ptlista, 43);

    print_lista(ptlista);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int chave;
    int h;
    struct NODE* esquerda;
    struct NODE* direita;
} Node;

//GLOBAL
Node* raiz;

Node* inicializa(int chave){
    Node* no = (Node*) malloc(sizeof(Node));
    no->chave = chave;
    no->direita = NULL;
    no->esquerda = NULL;
    no->h = 0;
    return no;
}

Node* roda_direita(Node* no){
    Node* aux;
    aux = no->esquerda;
    no->esquerda = aux->direita;
    aux->direita = no;

    no->h = max(altura(no->direita), altura(no->esquerda)) + 1;
    aux->h = max(altura(aux->esquerda), no->h) + 1;

    return(aux);
}
int main(){
    raiz = inicializa(10);
    return 0;
}
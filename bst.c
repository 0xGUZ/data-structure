#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int chave;
    int soma;
    struct NODE* esquerda;
    struct NODE* direita;
} Node;

//GLOBAIS
Node* ptraiz;
//

Node* inicializa(Node* raiz, int chave){
    raiz = (Node*) malloc (sizeof(Node));
    raiz->chave = chave;
    raiz->direita = NULL;
    raiz->esquerda = NULL;

    return raiz;
}

void insere(int chave, Node* pai){
    Node* no_inserir = (Node*) malloc (sizeof(Node));
    no_inserir->chave = chave;
    no_inserir->direita = NULL;
    no_inserir->esquerda = NULL;

    //esquerda
    if(chave <= pai->chave){
        if(pai->esquerda != NULL){
            insere(chave, pai->esquerda);
        }
        else{
            pai->esquerda = no_inserir;
        }
    }

    //direita
    if(chave > pai->chave){
        if(pai->direita != NULL){
            insere(chave, pai->direita);
        }
        else{
            pai->direita = no_inserir;
        }
    }
}

Node* busca(Node* ptraiz, int chave){
    Node* atual = ptraiz;

    if(atual->chave == chave){
        return atual;
    }

    //se o no q vc ta olhando tiver chave menor ent busque na direita
    else if(atual->chave < chave){
        busca(atual->direita, chave);
    }

    //se o no q vc ta olhando e menor ent olha na esquerda
    else{
        busca(atual->esquerda, chave);
    }
}

void print_bst(Node* no, int level){
    if(no == NULL){
        return;
    }

    else{
        printf("level%d: %d\n",level, no->chave);
        print_bst(no->esquerda,level+1);
        print_bst(no->direita,level+1);
    }
}

int contagem(Node* no){
    if(no == NULL){
        return 0;
    }

    return (1 + contagem(no->esquerda) + contagem(no->direita));
}

int main(){
    ptraiz = inicializa(ptraiz, 10);
    
    insere(5, ptraiz);
    insere(15, ptraiz);
    insere(20, ptraiz);

    printf("\n\n");
    print_bst(ptraiz, 0);
    printf("numero de nos %d",contagem(ptraiz));

    return 0;
}
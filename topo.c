#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vertice {
    int numero;
    int vizinhos[100];
    int grau_saida;
    int grau_entrada;
};

struct  Node{
    struct Vertice vertice;
    struct Node* proximo_node;
};

struct Node* head_nao_ordenados = NULL;
struct Node* head_ordenados = NULL;

struct Vertice vertices[100];
int num_vertices, num_arestas;
int num_v_nao_ordenados;

void start_vertices(){
    int i = 0;
    for(i = 0; i < 100; i++){
        vertices[i].numero = 0;
        vertices[i].grau_saida = 0;
        vertices[i].grau_entrada = 0;
    }
}

void append_node(struct Node* head, struct Node* node_to_append){
    struct Node* node_atual = head;

    while(node_atual->proximo_node != NULL){
        node_atual = node_atual->proximo_node;
    }

    node_atual->proximo_node = node_to_append;
    node_to_append->proximo_node = NULL;
}

void remove_node(struct Node* head, struct Node* node_to_remove){
    struct Node* node_atual = head;
    struct Node* node_anterior = NULL;
    
    if(node_to_remove == head){
        printf("você nao pode apagar o head");
        return;
    }

    while(node_atual != node_to_remove){
        node_anterior = node_atual;
        node_atual = node_atual->proximo_node;

        if(node_atual == NULL){
            return;
        }
    }

    node_anterior->proximo_node = node_to_remove->proximo_node;
}

void start_nao_ordenados(){
    int i;
    head_nao_ordenados = (struct Node*) malloc(sizeof(struct Node));
    head_nao_ordenados->proximo_node = NULL;

    for(i = 0; i < num_vertices; i++){
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->vertice = vertices[i];
        node->proximo_node = NULL;
        append_node(head_nao_ordenados, node);
    }
}

void start_ordenados(){
    head_ordenados = (struct Node*) malloc(sizeof(struct Node));
    head_ordenados->proximo_node = NULL;
}

void print_lista_ordenada(){
    struct Node* node_atual = head_ordenados->proximo_node;

    while(node_atual != NULL){
        printf("%d ", node_atual->vertice.numero);
        node_atual = node_atual->proximo_node;
    }

    printf("\n");
}

void print_lista_nao_ordenada(){
    struct Node* node_atual = head_nao_ordenados->proximo_node;

    while(node_atual != NULL){
        printf("%d ", node_atual->vertice.numero);
        node_atual = node_atual->proximo_node;
    }

    printf("\n");
}

void read_input(){
    scanf("%d %d", &num_vertices, &num_arestas);
    num_v_nao_ordenados = num_vertices;
    int i = 0;
    char line[200]; 
    getchar();
    while (fgets(line, 200, stdin) != NULL && i < num_vertices) {
        char* token = strtok(line, " ");
        int j = 0;
        while (token != NULL) {
            vertices[i].numero = i+1;
            vertices[i].vizinhos[j++] = atoi(token); 
            vertices[i].grau_saida++;
            token = strtok(NULL, " "); // anda pro prox token
        }
        i++;
    }
}

void move_grau_zero(){
    int i, j;
    struct Node* node_atual = head_nao_ordenados->proximo_node;

    while(node_atual != NULL){
        
        if(node_atual->vertice.grau_entrada == 0){
            remove_node(head_nao_ordenados, node_atual);
            append_node(head_ordenados, node_atual);
            return;
        }
                
        node_atual = node_atual->proximo_node;
    }

    printf("\nNenhum vértice tem grau 0. É cíclico.\n");
}

void zera_grau_entrada() {
    struct Node* node_atual = head_nao_ordenados->proximo_node;

    while (node_atual != NULL)
    {
        node_atual->vertice.grau_entrada = 0;
        node_atual = node_atual->proximo_node;
    }
    
}
int calcula_grau_entrada() {
    int i = 0, j = 0;

    if (num_v_nao_ordenados <= 0) {
        return 1;
    }

    zera_grau_entrada();
    
    struct Node* node_atual = head_nao_ordenados->proximo_node;
    struct Node* node_dentro;

    while (node_atual != NULL){
    
        for(i = 0; i < node_atual->vertice.grau_saida; i++){
            
            node_dentro = head_nao_ordenados->proximo_node;

            while(node_dentro != NULL){
                if(node_atual->vertice.vizinhos[i] == node_dentro->vertice.numero){
                    node_dentro->vertice.grau_entrada++;
                    break;
                }    
                node_dentro = node_dentro->proximo_node;
            }
        }
        node_atual = node_atual->proximo_node;
    }

    node_atual = head_nao_ordenados->proximo_node;
    while(node_atual != NULL){
        node_atual = node_atual->proximo_node;
    }
    
    move_grau_zero();
    --num_v_nao_ordenados;
    return 0;
}

void ordena(){
    int v = 0;
    while(v == 0){
        v = calcula_grau_entrada();
    }
}

void free_lista(struct Node* head){
    struct Node* node_atual = head;
    struct Node* prox_node = node_atual->proximo_node;
    while(prox_node != NULL){
        
    }
}

int main(){
    start_vertices();
    read_input();   
    start_nao_ordenados();
    start_ordenados();
    ordena();
    print_lista_ordenada();
    return 0;
}
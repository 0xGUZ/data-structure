#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int numero;
    int vizinhos[100];
    int num_vizinhos;
    int grau_entrada;
};

struct Node nodes[100];
int num_vertices, num_arestas;

int graus_entrada [100];
int output[100];

void start_nodes(){
    int i = 0;
    for(i = 0; i < 100; i++){
        nodes[i].num_vizinhos = 0;
        nodes[i].grau_entrada = 0;
    }
}

void read_input(){
    scanf("%d %d", &num_vertices, &num_arestas);
    int i = 0;
    char line[200]; 
    getchar();
    while (fgets(line, 200, stdin) != NULL && i < num_vertices) {
        char* token = strtok(line, " ");
        int j = 0;
        while (token != NULL) {
            nodes[i].vizinhos[j++] = atoi(token); 
            nodes[i].num_vizinhos++;
            token = strtok(NULL, " "); // anda pro prox token
        }
        i++;
    }
}

void print_vertices(int num_vertices){
    int i = 0, j=0;
    for (i=0; i<num_vertices; i++){
        printf("vertice %d: vizinhos ", i+1);
        for (j=0; j<nodes[i].num_vizinhos; j++){
            printf("{%d}, ", nodes[i].vizinhos[j]+1);
        }
        printf(" grau de entrada: %d\n", nodes[i].grau_entrada);
    }
}

void start_arr_grau_entrada_and_output(int num_vertices){
    int i = 0, j = 0;

    for (i = 0; i < num_vertices; i++){
        for (j = 0; j < nodes[i].num_vizinhos; j++){
            nodes[--nodes[i].vizinhos[j]].grau_entrada++;
            
        }
    }

    for (i = 0; i < num_vertices; i++){
        graus_entrada[i] = nodes[i].grau_entrada;
        output[i] = i;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordena_arr_graus_entrada_and_output(int arr_size){
    int i = 0, j = 0;
    for (i = 0; i < arr_size-1; i++){
        for (j = i; j < arr_size; j++){
            if(graus_entrada[j] < graus_entrada[i]){
                swap(&graus_entrada[j], &graus_entrada[i]);
                swap(&output[j], &output[i]);
            }        
        }
    }
}

void print_output_arr(int num_vertices){
    int i = 0, j = 0;
    printf("output\n");
    for (i = 0; i < num_vertices; i++){
        printf("%d ",output[i]+1);
    }
    printf("\ngraus entrada\n");
    for (i = 0; i < num_vertices; i++){
        printf("%d ",graus_entrada[i]);
    }
    printf("\n");
}

int main(){
    start_nodes();
    read_input();
    start_arr_grau_entrada_and_output(num_vertices);
    ordena_arr_graus_entrada_and_output(num_vertices);
    print_vertices(num_vertices);
    printf("\n\n");
    print_output_arr(num_vertices);
    return 0;
}
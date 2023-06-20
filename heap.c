#include<stdio.h>
#include<stdlib.h>

struct Aresta {
    int origem, destino, peso;
};

struct Grafo {
    int V, E;
    struct Aresta* aresta;
};

struct Grafo* criarGrafo(int V, int E) {
    struct Grafo* grafo = (struct Grafo*) malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->aresta = (struct Aresta*) malloc(grafo->E * sizeof(struct Aresta));
    return grafo;
}

int compara(const void* k1, const void* k2) {
    struct Aresta* a1 = (struct Aresta*)k1;
    struct Aresta* a2 = (struct Aresta*)k2;
    return a1->peso > a2->peso;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset!=yset) {
        parent[xset] = yset;
    }
}

int kruskalMST(struct Grafo* grafo) {
    int v, e, somaPeso = 0, x, y;
    struct Aresta result[grafo->V];
    qsort(grafo->aresta, grafo->E, sizeof(grafo->aresta[0]), compara);
    int *parent = (int*) malloc( grafo->V * sizeof(int));

    for (v = 0; v < grafo->V; ++v)
        parent[v]=-1;

    for(e = 0; e < grafo->E; e++) {
        x = find(parent, grafo->aresta[e].origem);
        y = find(parent, grafo->aresta[e].destino);
        if (x != y) {
            result[e] = grafo->aresta[e];
            somaPeso += grafo->aresta[e].peso;
            Union(parent, x, y);
        }
    }
    return somaPeso;
}

int main() {
    int V, E, i;

    printf("Insira o número de vértices: ");
    scanf("%d", &V);

    printf("Insira o número de arestas: ");
    scanf("%d", &E);

    struct Grafo* grafo = criarGrafo(V, E);

    for(i=0; i<E; i++){
        printf("Insira a origem, destino e peso da aresta %d: ", i+1);
        scanf("%d%d%d", &grafo->aresta[i].origem, &grafo->aresta[i].destino, &grafo->aresta[i].peso);
    }

    printf("Peso da árvore geradora mínima: %d\n", kruskalMST(grafo));

    return 0;
}

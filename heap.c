#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ARESTAS 1000

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
    grafo->aresta = (struct Aresta*) malloc(E * sizeof(struct Aresta));
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
    int *parent = (int*) malloc(grafo->V * sizeof(int));

    qsort(grafo->aresta, grafo->E, sizeof(grafo->aresta[0]), compara);

    for (v = 0; v < grafo->V; ++v)
        parent[v]=-1;

    for(e = 0; e < grafo->E; e++) {
        x = find(parent, grafo->aresta[e].origem);
        y = find(parent, grafo->aresta[e].destino);
        if (x != y) {
            somaPeso += grafo->aresta[e].peso;
            Union(parent, x, y);
        }
    }
    free(parent);
    return somaPeso;
}

void lerArestas(struct Grafo* grafo) {
    char line[200];
    int origem, destino, peso, i = 0;

    while(fgets(line, 200, stdin) != NULL && i < MAX_ARESTAS) {
        sscanf(line, "%d %d %d", &origem, &destino, &peso);

        grafo->aresta[i].origem = origem;
        grafo->aresta[i].destino = destino;
        grafo->aresta[i].peso = peso;

        i++;
    }

    grafo->E = i;
    grafo->aresta = realloc(grafo->aresta, i * sizeof(struct Aresta));
}

int main() {
    int V = MAX_ARESTAS;
    struct Grafo* grafo = criarGrafo(V, MAX_ARESTAS);

    lerArestas(grafo);

    printf("%d\n", kruskalMST(grafo));

    free(grafo->aresta);
    free(grafo);

    return 0;
}

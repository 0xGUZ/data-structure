#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int particiona(struct Aresta arr[], int baixo, int alto) {
    int pivot = arr[alto].peso;
    int i = (baixo - 1);
    int j;

    for (j = baixo; j <= alto - 1; j++) {
        if (arr[j].peso < pivot) {
            i++;
            struct Aresta temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct Aresta temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;

    return (i + 1);
}

void quickSort(struct Aresta arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int acha(int parente[], int i) {
    if (parente[i] == -1)
        return i;
    return acha(parente, parente[i]);
}

void uniao(int parente[], int x, int y) {
    int xset = acha(parente, x);
    int yset = acha(parente, y);
    if(xset!=yset) {
        parente[xset] = yset;
    }
}

int kruskalMST(struct Grafo* grafo) {
    int v, e, somaPeso = 0, x, y;
    int *parente = (int*) malloc(grafo->V * sizeof(int));

    quickSort(grafo->aresta, 0, grafo->E - 1);

    for (v = 0; v < grafo->V; ++v)
        parente[v]=-1;

    for(e = 0; e < grafo->E; e++) {
        x = acha(parente, grafo->aresta[e].origem);
        y = acha(parente, grafo->aresta[e].destino);
        if (x != y) {
            somaPeso += grafo->aresta[e].peso;
            uniao(parente, x, y);
        }
    }
    free(parente);
    return somaPeso;
}

void lerArestas(struct Grafo* grafo, int E) {
    int origem, destino, peso, i;
    
    for(i = 0; i < E; i++) {
        scanf("%d %d %d", &origem, &destino, &peso);

        grafo->aresta[i].origem = origem;
        grafo->aresta[i].destino = destino;
        grafo->aresta[i].peso = peso;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Grafo* grafo = criarGrafo(V, E);

    lerArestas(grafo, E);

    printf("%d\n", kruskalMST(grafo));

    free(grafo->aresta);
    free(grafo);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//chega se arg é -k
int argIsK(const char *arg) {
    if (arg[0] == '-' && arg[1] == 'k' && arg[2] == '\0') {
        return 1;
    }
    return 0;
}

int particiona(int arr[], int esquerda, int direita, int index_pivot) {
    int valor_pivot = arr[index_pivot];
    int temp = arr[direita];
    arr[direita] = arr[index_pivot];
    arr[index_pivot] = temp;

    int store_idx = esquerda;
    for (int i = esquerda; i < direita; i++) {
        if (arr[i] < valor_pivot) {
            temp = arr[i];
            arr[i] = arr[store_idx];
            arr[store_idx] = temp;
            store_idx++;
        }
    }

    temp = arr[direita];
    arr[direita] = arr[store_idx];
    arr[store_idx] = temp;
    return store_idx;
}

int quickSelect(int arr[], int esquerda, int direita, int k) {
    if (esquerda == direita)
        return arr[esquerda];

    int index_pivot = esquerda + rand() % (direita - esquerda + 1);
    index_pivot = particiona(arr, esquerda, direita, index_pivot);

    if (k == index_pivot)
        return arr[k];
    else if (k < index_pivot)
        return quickSelect(arr, esquerda, index_pivot - 1, k);
    else
        return quickSelect(arr, index_pivot + 1, direita, k);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso correto: quick-select -k <posicao>\n");
        return 1;
    }

    if (!argIsK(argv[1])) {
        printf("Argumento invalido: esperava -k <posicao>\n");
        return 1;
    }

    int k = atoi(argv[2]);

    int arr[10000];
    int n = 0;

    printf("\nDigite os números do array e pressione Ctrl+D para finalizar a entrada:\n\n");

    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    //se quer uma posicao maior que o size da array
    if(k>n){
        printf("\n\nNão dá pra pegar o %d-ésimo elemento, visto que a array só tem %d posições.\n", k, n);
        return 0;
    }

    printf("\n\nO %d-ésimo elemento é: %d\n", k, quickSelect(arr, 0, n - 1, k - 1));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//chega se arg é -k
int argIsK(const char *arg) {
    if (arg[0] == '-' && arg[1] == 'k' && arg[2] == '\0') {
        return 1;
    }
    return 0;
}

int particiona(int arr[], int inicio, int fim) {
    int index_pivot = inicio + rand() % (fim - inicio + 1);
    int valor_pivot = arr[index_pivot];
    arr[index_pivot] = arr[inicio];
    arr[inicio] = valor_pivot;
    
    int i = inicio + 1;
    int j = fim - 1;

    while (i < j){
        while (i < fim && arr[i] < valor_pivot){
            i++;
        }
        while (j > inicio && arr[j] >= valor_pivot){
            j--;
        }
        if (i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[inicio] = arr[j];
    arr[j] = valor_pivot;
    return j;
} 

int quickSelect(int arr[], int inicio, int fim, int k) {
    if (inicio == fim || fim - inicio == 1)
        return arr[inicio];

    int index_pivot = particiona(arr, inicio, fim);

    if (index_pivot == k)
        return arr[k];
    else if (index_pivot > k)
        return quickSelect(arr, inicio, index_pivot, k);
    else
        return quickSelect(arr, index_pivot, fim, k);
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

    int k = atoi(argv[2]) - 1;

    int arr[10000];
    int n = 0;

    while (scanf("%d", &arr[n]) != EOF) {
        n++;
    }

    //se quer uma posicao maior que o size da array
    if(k>n){
        printf("Não dá pra pegar o %d-ésimo elemento, visto que a array só tem %d posições.\n", k, n);
        return 0;
    }

    printf("%d", quickSelect(arr, 0, n - 1, k));
    return 0;
}
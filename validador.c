/**
* Entrada: Na primeira linha, o numero N de vertices, nas N linhas
* seguintes, todos os vizinhos de i separados por espaco, sendo i o numero
* da linha. Depois, uma ordenacao dos vertices, tambem separados por espaco.
*
* Saida: Confirmacao se a ordenacao dada eh uma uma ordenacao topologica
* do grafo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ARRAYDINAMICO {
	int *vetor;
	int tam;
	int nElem;
} ArrayDInt;

/* Funcoes do array dinamico */
int init (ArrayDInt *arr);
int push (int N, ArrayDInt *arr) ;
void overflow (ArrayDInt *arr);

int main (void) {
    int nVertices;
    int i, j, k, ch;
    ArrayDInt *grafo;
    ArrayDInt respostaDada;
    char num[20];

    fgets(num, 20, stdin);
	nVertices = atoi(num);

    /* Le a entrada que voce deu pro seu programa */
    grafo = malloc (sizeof *grafo * (nVertices + 1));
    if (grafo == NULL) {
        fprintf(stderr, "\n[ERRO] Sem memoria\n");
		exit(1);
    }

    for (i = 1; i <= nVertices; i++)
	{
		init(&grafo[i]);
		while (1)
		{
            j = 0; /* Vizinhos ja lidos de i */
			while('0' <= (ch = getchar()) && ch <=  '9') {
				num[j++] = ch;
			}
			if (j > 0) {
				num[j] = '\0';
				push(atoi(num), &grafo[i]);
				j = 0;
			}
			if (ch == EOF || ch == '\n')
				break;
		}
	}

    printf("\nOrdenacao encontrada: ");

    init(&respostaDada);
    /* Le a saida do seu programa */
    for (i = 1; i <= nVertices; i++) {
        j = 0;
        while('0' <= (ch = getchar()) && ch <=  '9')
				num[j++] = ch;

        if (j > 0) {
				num[j] = '\0';
				push(atoi(num), &respostaDada);
				j = 0;
		}
        else {
            i--;
            continue;
        }
    }

    if (respostaDada.nElem != nVertices) {
        printf("Errado. O numero de vertices na sua ordenacao eh diferente"
        " do numero de vertices no grafo.\n");
        return 1;
    }
    for (i = 0; i < nVertices; i++) {
        for (j = i + 1; j < nVertices; j++) {
            if (respostaDada.vetor[i] == respostaDada.vetor[j])
            {
                printf("Errado. Cada vertice so deve aparecer uma vez na"
                "ordenacao... %d apareceu mais de uma\n", respostaDada.vetor[i]);
                return 1;
            }
        }
    }
    for (i = 0; i < nVertices; i++)
    {
        for (j = 0; j < i; j++)
        {
            for(k = 0; k < grafo[respostaDada.vetor[i]].nElem; k++) {
                if (grafo[respostaDada.vetor[i]].vetor[k] == respostaDada.vetor[j]) {
                    printf("Errado. %d depende de %d, e aparece antes na ordenacao\n",
                    respostaDada.vetor[j], respostaDada.vetor[i]);
                    return 1;
                }
            }
        }
    }

    printf("A ordenacao eh valida, boa\n");       
    return 0;
}

int init (ArrayDInt *arr)
{
	if (!(arr->vetor = malloc(10 * sizeof(*(arr->vetor)))))
		return 0;

	arr->tam = 10;
	arr->nElem = 0;
	return 1;
}

int push (int N, ArrayDInt *arr) 
{
	if (arr->nElem == arr->tam) 
		overflow (arr);
		
    arr->vetor[arr->nElem++] = N;
	return N;
}

void overflow (ArrayDInt *arr)
{
    int i;
    int newT = arr->tam * 2;
    int *newV; 

    if (!(newV = malloc(newT * sizeof(*(arr->vetor))))) {
        fprintf(stderr, "\n[ERRO] Sem memoria\n");
		exit(1);
    }

    for (i = 0; i < arr->nElem; ++i) {
        newV[i] = arr->vetor[i];
    }

    free(arr->vetor);
    arr->vetor = newV;
    arr->tam = newT;
    
    return;
}
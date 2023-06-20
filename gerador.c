/**
* Modo de uso: Muda o TAM ali no define pra definir quantos vertices voce
* quer no grafo de saida. 
* Por padrao, a saida eh salva em um arquivo chamado "out.txt", mas se 
* quiser escolher o nome, chama o programa com -f [nome do arquivo] 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAM 50

int stringIgual (const char *, const char *);

int main (int argc, char *argv[])
{
    int ordenacaoTopologica[TAM + 1];
    int posicao[TAM + 1];
    int linhaDeVizinhos[TAM];
    int i, j, k;
    int pos;
    int numVizinhos;
    int padrao = 1;
    FILE *out;

    for (i = 1; i < argc - 1; i++) {
		if (!strcmp("-f", argv[i])) {
			out = fopen(argv[i + 1], "w");
            padrao = 0;
		}
    }
    if (padrao)
        out = fopen("out.txt", "w");

    srand(time(NULL));
    for (i = 1; i <= TAM; i++)
        ordenacaoTopologica[i] = 0;

    i = 1;
    /* Gera uma ordenacao aleatoria primeiro, com todos os numeros de 1 a TAM
    embaralhados */
    while (i <= TAM) {
        pos = rand() % TAM + 1;
        if (ordenacaoTopologica[pos] == 0) {
            ordenacaoTopologica[pos] = i;
            posicao[i++] = pos; 
            /* Vai ser util acessar a posicao de i nessa ordenacao dps */
        }
    }

    fprintf(out, "%d 3\n", TAM); /* Entrada comeca com o numero de vertices */

    /* Designa os vizinhos de cada vertice, em ordem, como eh feito na entrada */
    for (i = 1; i <= TAM; i++) {
        numVizinhos = TAM - posicao[i]; /* i so pode ter vizinhos a frente dele
        na ordenacao, pra garantir que ela eh topologica */

        if (numVizinhos != 0) 
            numVizinhos = rand() % numVizinhos; 
            /* Caso contrario i sempre teria todos os vizinhos
            possiveis... so pra variar o numero */

        for (j = 0; j < numVizinhos; j++) {
            linhaDeVizinhos[j] = ordenacaoTopologica[posicao[i] + (rand() % numVizinhos) + 1];
            for (k = 0; k < j; k++) {
                if (linhaDeVizinhos[k] == linhaDeVizinhos[j]) { 
                    /* Cancela vizinhos repetidos */
                    j--;
                    break;
                }
            }
        }

        for (j = 0; j < numVizinhos; j++) /* Todos os vizinhos de i */ {
            fprintf(out, "%d ", linhaDeVizinhos[j]);
        }
        fprintf(out, "\n"); /* Eh uma linha, como dizia o nome da variavel :O */
    }
    fclose(out);

    return 0; 
}
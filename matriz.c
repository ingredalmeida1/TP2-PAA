#include "matriz.h"

void inicializaMatriz(int N, int M, Posicao ***matriz)
{
    (*matriz) = (Posicao **)malloc(N * sizeof(Posicao *));

    for (int i = 0; i < N; i++)
    {
        (*matriz)[i] = (Posicao *)malloc(M * sizeof(Posicao));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            (*matriz)[i][j].valor = 0;
            (*matriz)[i][j].somaMin = -1;
        }
    }
}

void imprimeMatriz(int N, int M, Posicao **matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("% d ", matriz[i][j].valor);
        }
        printf("\n");
    }
}
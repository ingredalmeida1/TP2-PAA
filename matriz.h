#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct posicao
{
    int valor;
    int somaMin;
} Posicao;

void inicializaMatriz(int N, int M, Posicao ***matriz);

void imprimeMatriz(int N, int M, Posicao **matriz);
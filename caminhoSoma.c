#include "caminhoSoma.h"

int qtdCaminhos = 1;

int calculaSoma(Posicao ***matriz, int linha, int coluna, int soma, int N, int M)
{
    int minDireita = -1;
    int minAbaixo = -1;
    soma += (*matriz)[linha][coluna].valor; // recebe o valor da posição e soma com o valor que estava em soma

    if (coluna + 1 < M) // verifica primeiro a direita
    {
        if ((*matriz)[linha][coluna + 1].somaMin != -1) // se o valor de somaMin é diferente de -1, quer dizer que ele ja foi calculado
        {
            minDireita = (*matriz)[linha][coluna + 1].somaMin;
        }
        else // se for -1, precisamos calcular
        {
            minDireita = calculaSoma(matriz, linha, coluna + 1, soma, N, M);
        }
    }

    if (linha + 1 < N) // verifica abaixo
    {
        if ((*matriz)[linha + 1][coluna].somaMin != -1)
        {
            minAbaixo = (*matriz)[linha + 1][coluna].somaMin; // se o valor de somaMin é diferente de -1, quer dizer que ele ja foi calculado
        }
        else // se for -1, precisamos calcular
        {
            minAbaixo = calculaSoma(matriz, linha + 1, coluna, soma, N, M);
        }
    }

    // o valor de somaMin deve ser a soma entre o minimo das duas opções de caminho + o valor da posição
    (*matriz)[linha][coluna].somaMin = minimo(minAbaixo, minDireita) + (*matriz)[linha][coluna].valor;
    // retorna o valor de somaMin da posição (0, 0)
    return (*matriz)[linha][coluna].somaMin;
}

int minimo(int abaixo, int direita)
{
    // exceções: quando os valores ainda não foram calculados
    if (abaixo == -1 && direita == -1)
    {
        return 0;
    }
    if (abaixo == -1 && direita != -1)
    {
        return direita;
    }
    if (abaixo != -1 && direita == -1)
    {
        return abaixo;
    }
    // casos simples
    if (abaixo >= direita)
    {
        return direita;
    }
    else
    {
        return abaixo;
    }
}

void quantidadeCaminhos(Posicao **matriz, int linha, int coluna, int N, int M)
{
    int somaMin = (matriz)[linha][coluna].somaMin;
    int somaDireita = 0;
    int somaAbaixo = 0;
    int quant = 0;

    if (coluna + 1 < M)
    {
        somaDireita = matriz[linha][coluna].valor + matriz[linha][coluna + 1].somaMin;
        if (somaDireita == somaMin)
        {
            quant++;
            quantidadeCaminhos(matriz, linha, coluna + 1, N, M);
        }
    }

    if (linha + 1 < N)
    {
        somaAbaixo = matriz[linha][coluna].valor + matriz[linha + 1][coluna].somaMin;
        if (somaAbaixo == somaMin)
        {
            quant++;
            quantidadeCaminhos(matriz, linha + 1, coluna, N, M);
        }
    }

    if (quant == 2)
    {
        qtdCaminhos++;
    }
}

void imprimeQuantidadeCaminhos()
{
    printf("Quantidade de caminhos: %d\n", qtdCaminhos);
}
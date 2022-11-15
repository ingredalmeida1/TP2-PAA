#include "arquivo.h"

void lerArquivo(Posicao ***matriz)
{
    FILE *arquivo;
    int N, M;
    char entrada[20];

    printf("Entre com o nome do arquivo: ");
    scanf("%s", entrada);
    printf("\n");

    arquivo = fopen(entrada, "r"); // abre o arquivo em modo leitura
    if (arquivo == NULL)           // caso arquivo seja igual a NULL, encerra
    {
        printf("Erro na abertura do arquivo ou arquivo vazio\n");
        system("pause");
        exit(1);
    }

    fscanf(arquivo, "%d %d ", &N, &M);

    inicializaMatriz(N, M, matriz);

    while (!feof(arquivo))
    {
        int n;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                fscanf(arquivo, "%d", &n);
                (*matriz)[i][j].valor = n;
            }
        }
    }

    //imprimeMatriz(N, M, (*matriz));

    int somaMin = calculaSoma(matriz, 0, 0, 0, N, M);
    printf("SOMA MÍNIMA: %d\n", somaMin);

    quantidadeCaminhos((*matriz), 0, 0, N, M);
    imprimeQuantidadeCaminhos();
}
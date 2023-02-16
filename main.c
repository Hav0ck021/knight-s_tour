#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

void tabela_informativa(int i, int j, int movimento, int qtd_movimento, int erro_cont)
{
    printf("\n\nQtde de movimentos-> %d\n\n", qtd_movimento);
    printf("Movimento usado | Qtde de erro-> %d | %d\n\n", movimento, erro_cont);
    printf("Linha | Coluna-> %d | %d \n\n", i, j);
    printf("=============================================================\n\n");
}

void movimentos_do_cavalo (int i, int j, int matriz[TAM][TAM])
{
    int nao_visitadas, movimento = 0, cont = 2, qtd_movimento = 1, erro_cont = 0;
    int pX[8] = {2,1,-1,-2,-2,-1,1,2}, pY[8] = {1,2,2,1,-1,-2,-2,-1};
    matriz[i][j] = 1;

    while(erro_cont != 8)
    {
        movimento = rand() % 8;

        switch(movimento)
        {
            case 0:
                if (i >= 0 && i + pX[0] <= (TAM - 1) && j >= 0 && j + pY[0] <= (TAM - 1) && matriz[i + pX[0]][j + pY[0]] == 0)
                {
                    i = i + pX[0];
                    j = j + pY[0];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 1:
                if (i >= 0 && i + pX[1] <= (TAM - 1) && j >= 0 && j + pY[1] <= (TAM - 1) && matriz[i + pX[1]][j + pY[1]] == 0)
                {
                    i = i + pX[1];
                    j = j + pY[1];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 2:
                if (i <= (TAM - 1) && i + pX[2] >= 0 && j >= 0 && j + pY[2] <= (TAM - 1) && matriz[i + pX[2]][j + pY[2]] == 0)
                {
                    i = i + pX[2];
                    j = j + pY[2];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 3:
                if (i <= (TAM - 1) && i + pX[3] >= 0 && j >= 0 && j + pY[3] <= (TAM - 1) && matriz[i + pX[3]][j + pY[3]] == 0)
                {
                    i = i + pX[3];
                    j = j + pY[3];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 4:
                if (i >= 0 && i + pX[4] <= (TAM - 1) && j >= 0 && j + pY[4] <= (TAM - 1) && j + pY[4] >= 0 && matriz[i + pX[4]][j + pY[4]] == 0)
                {
                    i = i + pX[4];
                    j = j + pY[4];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 5:
                if (i <= (TAM - 1) && i + pX[5] >= 0 && j <= (TAM - 1) && j + pY[5] >= 0 && matriz[i + pX[5]][j + pY[5]] == 0)
                {
                    i = i + pX[5];
                    j = j + pY[5];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 6:
                if (i <= (TAM - 1) && i + pX[6] >= 0 && j <= (TAM - 1) && j + pY[6] >= 0 && matriz[i + pX[6]][j + pY[6]] == 0)
                {
                    i = i + pX[6];
                    j = j + pY[6];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
            case 7:
                if (i >= 0 && i + pX[7] <= (TAM - 1) && j <= (TAM - 1) && j + pY[7] >= 0 && matriz[i + pX[7]][j + pY[7]] == 0)
                {
                    i = i + pX[7];
                    j = j + pY[7];
                    matriz[i][j] = cont;
                    cont++;
                    qtd_movimento++;
                    erro_cont = 0;
                    break;
                }
                else
                {
                    erro_cont++;
                    break;
                }
        }
        saida_tabuleiro(matriz);
        tabela_informativa(i, j, movimento, qtd_movimento, erro_cont);
        nao_visitadas = TAM*TAM - qtd_movimento;
    }
    printf("Casas visitadas | Casas nao visitadas-> %d | %d \n\n", qtd_movimento, nao_visitadas);
}


int tabuleiro_inicial (int matriz[TAM][TAM])
{
    int cont = 1;

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            matriz[i][j] = 0;
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int saida_tabuleiro (int matriz[TAM][TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    int i, j, movimento, cont = 1;
    int tab[TAM][TAM] = {0};

    srand(time(NULL));

    printf("Passeio do Cavalo Desgovernado\n\n");
    tabuleiro_inicial(tab);
    printf("\nBem vindo ao nosso programa!\n");
    printf("\nPara iniciar os movimentos do cavalo, insira a posicao inicial do cavalo\n");
    scanf("%d  %d", &i, &j);

    while (i > (TAM - 1) || i < 0 || j > (TAM - 1) || j < 0)
    {
        printf("Numeros invalidos, insira novamente\n");
        scanf("%d  %d", &i, &j);
    }

    tab[i][j] = cont;
    movimentos_do_cavalo(i, j, tab);

    return 0;
}

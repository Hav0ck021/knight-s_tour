#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

int main()
{
    int i, j, movimento;
    int tab[TAM][TAM] = {0};
    int pX = {2,1,-1,-2,-2,-1,1,2}, pY = {1,2,2,1,-1,-2,-2,-1};

    srand(time(NULL));

    scanf("%d", &i);
    scanf("%d", &j);

    movimento = rand() % 7;

    tab[i][j] = 1;

    while((i >= 0 && i < 8) && (j >= 0 && j < 8))
    {
        int m, n;

        m = i + pX[movimento];
        n = j + pX[movimento];

        if(tab[m][n] == 0)
        {
            tab[m][n] += 1;
        }
        else
        {

        }
    }


    for(i = 0; i < TAM; i++)
        {
            for(j = 0; j < TAM; j++)
            {
                printf("| %d |", tab[i][j]);
            }
            printf("\n");
        }

    return 0;
}

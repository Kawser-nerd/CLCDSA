#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 55

static char a[MAXN][MAXN];
int N;

char GetA (int x, int y)
{
    if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) return '.';
    else return a[x][y];
}

char IsK (int x, int y, int dx, int dy, char what, int K)
{
    while (K > 0)
    {
        if (GetA(x,y) != what) return 0;
        x += dx;
        y += dy;
        K--;
    }
    return 1;
}

char FindIs (char what, int K)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (IsK(i,j,0,1,what,K)) return 1;
            if (IsK(i,j,1,0,what,K)) return 1;
            if (IsK(i,j,-1,1,what,K)) return 1;
            if (IsK(i,j,-1,-1,what,K)) return 1;
        }
    }
    return 0;
}

int main ()
{
    int T, iT;
    scanf("%d",&T);
    for (iT = 0; iT < T; iT++)
    {
        int K;
        int i, j;
        scanf("%d %d\n",&N,&K);
        for (i = 0; i < N; i++)
        {
            scanf("%s\n",a[i]);
        }
        int last;
        for (i = 0; i < N; i++)
        {
            last = N;
            for (j = N-1; j >= 0; j--)
            {
                if (a[i][j] != '.')
                {
                    last--;
                    a[i][last] = a[i][j];
                }
            }
            for (j = last-1; j >= 0; j--) a[i][j] = '.';
        }
        char bl = FindIs('B',K);
        char rd = FindIs('R',K);
        printf("Case #%d: ",iT+1);
        if (bl && rd) printf("Both\n");
        else if (bl) printf("Blue\n");
        else if (rd) printf("Red\n");
        else printf("Neither\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 105

int GetCount (char a[MAXN][MAXN], int N)
{
    int res = 0;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[i][j]) res++;
        }
    }
    return res;
}

int main ()
{
    int T, iT;
    scanf("%d",&T);
    static char a[MAXN][MAXN];
    static char a2[MAXN][MAXN];
    for (iT = 0; iT < T; iT++)
    {
        memset(a,0,sizeof(a));
        int x1, y1, x2, y2;
        int K;
        scanf("%d",&K);
        int i, x, y;
        int N = 0;
        for (i = 0; i < K; i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if (x2 > N) N = x2;
            if (y2 > N) N = y2;
            x1--; y1--; x2--; y2--;
            for (x = x1; x <= x2; x++)
            {
                for (y = y1; y <= y2; y++)
                {
                    a[x][y] = 1;
                }
            }
        }
        int res = 0;
        while (GetCount(a,N) > 0)
        {
            memset(a2,0,sizeof(a2));
            for (x = 1; x < N; x++)
            {
                for (y = 1; y < N; y++)
                {
                    if (a[x][y])
                    {
                        if ((a[x-1][y]) || (a[x][y-1])) a2[x][y] = 1;
                    }
                    else
                    {
                        if ((a[x-1][y]) && (a[x][y-1])) a2[x][y] = 1;
                    }
                }
            }
            memcpy(a,a2,sizeof(a2));
            res++;
        }
        printf("Case #%d: %d\n",iT+1,res);
    }
    return 0;
}

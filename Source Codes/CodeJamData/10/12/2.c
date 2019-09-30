#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
#define MAXNUM 256
#define INFINITY 2000000000

int main ()
{
    int T, iT;
    scanf("%d",&T);
    static int a[MAXN][MAXNUM+5];
    static int atmp[MAXNUM+5];
    for (iT = 0; iT < T; iT++)
    {
        int D, I, M, N;
        scanf("%d %d %d %d",&D,&I,&M,&N);
        int i, j, k;
        for (i = 0; i < MAXNUM; i++) a[0][i] = INFINITY;
        a[0][MAXNUM] = 0;
        
        for (i = 1; i <= N; i++)
        {
            for (j = 0; j <= MAXNUM; j++)
            {
                a[i][j] = INFINITY;
            }
            int num, temp;
            scanf("%d",&num);
            for (j = 0; j <= MAXNUM; j++)
            {
                if (a[i-1][j] != INFINITY)
                {
                    temp = a[i-1][j] + D;
                    if (temp < a[i][j]) a[i][j] = temp;
                    for (k = 0; k < MAXNUM; k++)
                    {
                        if ((j == MAXNUM) || (abs(k-j) <= M))
                        {
                            temp = a[i-1][j] + abs(k-num);
                            if (temp < a[i][k]) a[i][k] = temp;  
                        }
                    }
                    if ((j == MAXNUM) || (abs(num-j) <= M))
                    {
                        temp = a[i-1][j];
                        if (temp < a[i][num]) a[i][num] = temp;
                    }
                }
            }
            char flag = 1;
            while (flag)
            {
                flag = 0;
                atmp[MAXNUM] = a[i][MAXNUM];
                for (k = 0; k < MAXNUM; k++)
                {
                    atmp[k] = a[i][k];
                    for (j = 0; j <= MAXNUM; j++)
                    {
                        if ((j == MAXNUM) || (abs(k-j) <= M))
                        {
                            temp = a[i][j] + I;
                            if (temp < atmp[k])
                            {
                                atmp[k] = temp;
                                flag = 1;
                            }
                        }
                    }
                }
                for (k = 0; k <= MAXNUM; k++) a[i][k] = atmp[k];
            }
        }
        
        int res = INFINITY;
        for (j = 0; j <= MAXNUM; j++)
        {
            if (a[N][j] < res) res = a[N][j];
        }
        printf("Case #%d: %d\n",iT+1,res);
    }
    return 0;
}

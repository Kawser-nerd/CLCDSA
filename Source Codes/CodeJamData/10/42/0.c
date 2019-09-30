#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 2100
#define MAXP 15
#define INFINITY 1000000005

int main ()
{
    int T, iT;
    scanf("%d",&T);
    static int ms[MAXN];
    static int pr[MAXN][MAXN];
    static int a[MAXN][MAXN][MAXP];
    for (iT = 0; iT < T; iT++)
    {
        int P, N;
        scanf("%d",&P);
        N = 1 << P;
        int i;
        for (i = 0; i < N; i++) 
        {
            scanf("%d",&(ms[i]));
            ms[i] = P - ms[i];
        }
        int temp = 1 << P;
        int prc = 0;
        int j, k;
        do
        {
            prc++;
            temp /= 2;
            for (j = 0; j < temp; j++) scanf("%d",&(pr[prc][j]));
        } while (temp > 1);
        for (j = 0; j < N; j++)
        {
            for (k = 0; k <= P; k++) a[0][j][k] = INFINITY;
            a[0][j][ms[j]] = 0;
        }
        
        temp = 1 << P;
        int x, y;
        int sum;
        for (i = 1; i <= prc; i++)
        {
            temp /= 2;
            for (j = 0; j < temp; j++)
            {
                for (k = 0; k <= P; k++)
                {
                    a[i][j][k] = INFINITY;
                    //a) Taking
                    if (k < P)
                    {
                        x = k+1;
                        for (y = 0; y <= (k+1); y++)
                        {
                            sum = pr[i][j] + a[i-1][2*j][x] + a[i-1][2*j+1][y];
                            if (sum < a[i][j][k]) a[i][j][k] = sum;
                        }
                        y = k+1;
                        for (x = 0; x <= (k+1); x++)
                        {
                            sum = pr[i][j] + a[i-1][2*j][x] + a[i-1][2*j+1][y];
                            if (sum < a[i][j][k]) a[i][j][k] = sum;                            
                        }
                    }
                    //b) Not taking
                    x = k;
                    for (y = 0; y <= k; y++)
                    {
                        sum = a[i-1][2*j][x] + a[i-1][2*j+1][y];
                        if (sum < a[i][j][k]) a[i][j][k] = sum;
                    }
                    y = k;
                    for (x = 0; x <= k; x++)
                    {
                        sum = a[i-1][2*j][x] + a[i-1][2*j+1][y];
                        if (sum < a[i][j][k]) a[i][j][k] = sum;
                    }
                }
            }
        }
        
               
        printf("Case #%d: %d\n",iT+1,a[prc][0][0]);
    }
    return 0;
}

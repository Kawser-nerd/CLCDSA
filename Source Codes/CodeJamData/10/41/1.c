#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 505
#define INFINITY 2000000005

int Module (int a)
{
    if (a >= 0) return a;
    else return -a;
}

char IsEqual (int a, int b)
{
    if ((a == -1) || (b == -1)) return 1;
    if (a != b) return 0;
    else return 1;
}

char Check (int a[MAXN][MAXN], int N, int x, int y)
{
    int x1, x2, y1, y2, i, j;
    x1 = x-1;
    x2 = x+1;
    while ((x1 >= 0) && (x2 < N))
    {
        for (j = 0; j < N; j++)
        {
            if (!IsEqual(a[x1][j],a[x2][j])) return 0;
        }
        x1--; x2++;
    }
    y1 = y-1;
    y2 = y+1;
    while ((y1 >= 0) && (y2 < N))
    {
        for (i = 0; i < N; i++)
        {
            if (!IsEqual(a[i][y1],a[i][y2])) return 0;
        }
        y1--; y2++;
    }
    return 1;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int a[MAXN][MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d",&N);
		int i, j;
		for (i = 0; i < MAXN; i++)
		{
            for (j = 0; j < MAXN; j++)
            {
                a[i][j] = -1;
            }   
        }
		for (i = 0; i < N; i++)
		{
			for (j = (N-i-1); j <= (N+i); j += 2)
			{
				scanf("%d",&(a[i][j]));
			}
		}
		for (i = N; i < (2*N-1); i++)
		{
			for (j = (i-N+1); j < (i-N+2*(2*N-i-1)); j += 2)
			{
				scanf("%d",&(a[i][j]));
			}
		}
		/*
		for (i = 0; i < (2*N-1); i++)
		{
            for (j = 0; j < (2*N-1); j++)
            {
                if (a[i][j] == -1) printf(" ");
                else printf("%d",a[i][j]);
            }
            printf("\n");
        }
        */
        int res = INFINITY;
        int x, y;
        for (x = 0; x < (2*N-1); x++)
        {
            for (y = 0; y < (2*N-1); y++)
            {
                int ns = N + Module(N-1-x) + Module(N-1-y);
                if (ns < res)
                {
                    if (Check(a,2*N-1,x,y))
                    {
                        res = ns;
                    }
                }
            }
        }
		
		res = res * res - N * N;
		printf("Case #%d: %d\n",iT+1,res);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

#define INFINITO	0x3F3F3F3F

#define MAXN		128

#define NUMM		10007

int	pd[MAXN][MAXN];
char	mrc[MAXN][MAXN];
int	m,
	n;

int main (void)
{
	int	nc,
		h;
	int	i,
		j,
		k;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%d%d", &m, &n);
		memset(mrc, 0, sizeof(mrc));
		for (scanf("%d", &k); k > 0; k--)
		{
			scanf("%d%d", &i, &j);
			mrc[i][j] = 1;
		}
		memset(pd, 0, sizeof(pd));
		pd[1][1] = 1;
		for (i = 2; i <= m; i++)
		{
			for (j = 2; j <= n; j++)
			{
				if (mrc[i][j]) continue;
				pd[i][j] = (pd[i][j] + pd[i - 2][j - 1]) % NUMM;
				pd[i][j] = (pd[i][j] + pd[i - 1][j - 2]) % NUMM;
			}
		}
		printf("Case #%d:", h);
		printf(" %d\n", pd[m][n]);
	}

	return 0;
}

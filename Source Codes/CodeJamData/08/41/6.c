#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b)	(((a) < (b)) ? (a) : (b))
#define MAX(a,b)	(((a) > (b)) ? (a) : (b))

#define INFINITO	0x3F3F3F3F

#define MAXM		(1 << 14)

int	b[MAXM][2];
int	m;

int	g[MAXM],
	c[MAXM];

int main (void)
{
	int	nc,
		h;
	int	v;
	int	i,
		j,
		k;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%d%d", &m, &v);
		for (i = 0; i < ((m - 1) / 2); i++)
		{
			scanf("%d%d", &(g[i]), &(c[i]));
		}
		for ( ; i < m; i++)
		{
			scanf("%d", &(g[i]));
		}
		memset(b, INFINITO, sizeof(b));
		for (i = (m - 1); i >= ((m - 1) / 2); i--)
		{
			if (g[i] == 0)
			{
				b[i][0] = 0;
				b[i][1] = INFINITO;
			}
			else
			{
				b[i][0] = INFINITO;
				b[i][1] = 0;
			}
		}
		for ( ; i >= 0; i--)
		{
			j = (i * 2) + 1;
			k = (i * 2) + 2;
			if (g[i] == 0)
			{
				if ((b[j][0] < INFINITO) && (b[k][0] < INFINITO))
				{
					b[i][0] = b[j][0] + b[k][0];
				}
				if ((b[j][1] < INFINITO) || (b[k][1] < INFINITO))
				{
					b[i][1] = MIN(b[j][1], b[k][1]);
				}
				if (c[i])
				{
					if ((b[j][0] < INFINITO) || (b[k][0] < INFINITO))
					{
						b[i][0] = MIN(b[i][0], MIN(b[j][0], b[k][0]) + 1);
					}
					if ((b[j][1] < INFINITO) && (b[k][1] < INFINITO))
					{
						b[i][1] = MIN(b[i][1], b[j][1] + b[k][1] + 1);
					}
				}
			}
			else
			{
				if ((b[j][0] < INFINITO) || (b[k][0] < INFINITO))
				{
					b[i][0] = MIN(b[j][0], b[k][0]);
				}
				if ((b[j][1] < INFINITO) && (b[k][1] < INFINITO))
				{
					b[i][1] = b[j][1] + b[k][1];
				}
				if (c[i])
				{
					if ((b[j][0] < INFINITO) && (b[k][0] < INFINITO))
					{
						b[i][0] = MIN(b[i][0], b[j][0] + b[k][0] + 1);
					}
					if ((b[j][1] < INFINITO) || (b[k][1] < INFINITO))
					{
						b[i][1] = MIN(b[i][1], MIN(b[j][1], b[k][1]) + 1);
					}
				}
			}
		}
		printf("Case #%d: ", h);
		if (b[0][v] < INFINITO)
		{
			printf("%d\n", b[0][v]);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}

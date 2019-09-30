#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN		16
#define MAXM		128
#define MAXT		128

#define INFINITO	0x3F3F3F3F

typedef struct
{
	int	t;
	int	p[MAXT][2];
} Cust;

Cust	cust[MAXM];
int	m;

int	mrc[MAXN];
int	n;

int	r;
int	res[MAXN];

void bt (int s, int p)
{
	int	i,
		j;

	if (p == n)
	{
		if (s >= r)
		{
			return;
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < cust[i].t; j++)
			{
				if (mrc[cust[i].p[j][0]] == cust[i].p[j][1])
				{
					break;
				}
			}
			if (j == cust[i].t)
			{
				break;
			}
		}
		if (i < m)
		{
			return;
		}
		r = s;
		for (i = 0; i < n; i++)
		{
			res[i] = mrc[i];
		}
		return;
	}

	mrc[p] = 0;
	bt(s, p + 1);

	mrc[p] = 1;
	bt(s + 1, p + 1);
}

int main (void)
{
	int	nc,
		h;
	int	i,
		j;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &(cust[i].t));
			for (j = 0; j < cust[i].t; j++)
			{
				scanf("%d%d", &(cust[i].p[j][0]), &(cust[i].p[j][1]));
				(cust[i].p[j][0])--;
			}
		}
		printf("Case #%d:", h);
		memset(mrc, 0, sizeof(mrc));
		r = INFINITO;
		bt(0, 0);
		if (r < INFINITO)
		{
			for (i = 0; i < n; i++)
			{
				printf(" %d", res[i]);
			}
			printf("\n");
		}
		else
		{
			printf(" IMPOSSIBLE\n");
		}
	}

	return 0;
}

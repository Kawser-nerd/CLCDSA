#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN		1024
#define MAXM		128

#define NUMM		1000000007

int	a[MAXM];
int	m;

int	v[MAXN];
int	n;

int	b[MAXN];

int main (void)
{
	int	nc,
		h;
	int	x,
		y,
		z;
	int	tot;
	int	i,
		j;

	for (scanf("%d", &nc), h = 1; h <= nc; h++)
	{
		scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &(a[i]));
		}
		for (i = 0; i < n; i++)
		{
			v[i] = a[i % m];
			a[i % m] = ((long long)x * a[i % m] + (long long)y * (i + 1)) % z;
		}
		b[0] = 1;
		tot = b[0];
		for (i = 1; i < n; i++)
		{
			b[i] = 1;
			for (j = 0; j < i; j++)
			{
				if (v[j] < v[i])
				{
					b[i] = (b[i] + b[j]) % NUMM;
				}
			}
			tot = (tot + b[i]) % NUMM;
		}
		printf("Case #%d: %d\n", h, tot);
	}

	return 0;
}

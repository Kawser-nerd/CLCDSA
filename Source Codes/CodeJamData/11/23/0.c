#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 2005

struct node
{
	int a, b;	
};

struct cnode
{
	int cnt;
	int a[MAXN];	
};


int main ()
{
	int T, iT;
	scanf("%d",&T);
	static struct node a[MAXN];
	static char b[MAXN][MAXN];
	static int p[MAXN][MAXN];
	static struct cnode c[MAXN];
	static int resw[10];
	static int num[10];
	static char b2[10];
	int cc;
	for (iT = 0; iT < T; iT++)
	{
		int N, M;
		scanf("%d %d",&N,&M);
		int i;
		for (i = 0; i < M; i++)
		{
			scanf("%d",&(a[i].a));
			(a[i].a)--;
		}
		for (i = 0; i < M; i++)
		{
			scanf("%d",&(a[i].b));
			(a[i].b)--;
		}
		memset(b,0,sizeof(b));
		for (i = 0; i < M; i++)
		{
			b[a[i].a][a[i].b] = 1;
			b[a[i].b][a[i].a] = 1;
		}
		for (i = 0; i < N; i++)
		{
			b[i][(i-1+N) % N] = 1;
			b[i][(i+1) % N] = 1;
		}
		int j;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				p[i][j] = -1;
			}
		}
		int k, last;
		for (i = 0; i < N; i++)
		{
			last = (i-1+N) % N;
			j = (i+1) % N;
			while (j != last)
			{
				k = j;
				do
				{
					k = (k+1) % N;
				} while (b[i][k] == 0);
				p[j][i] = k;
				j = k;
			}
		}
		cc = 0;
		int totalmin = N;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (p[i][j] != -1)
				{
					c[cc].cnt = 0;
					int x, y, z;
					x = i; y = j;
					do
					{
						c[cc].a[c[cc].cnt] = x;
						(c[cc].cnt)++;
						z = p[x][y];
						p[x][y] = -1;
						x = y;
						y = z;
					} while ((x != i) || (y != j));
					if (c[cc].cnt < totalmin) totalmin = c[cc].cnt;
					cc++;
				}
			}
		}
		int res = 0;
		int total = 1;
		for (i = 0; i < N; i++) total *= N;
		for (i = 0; i < total; i++)
		{
			k = i;
			memset(b2,0,sizeof(b2));
			for (j = 0; j < N; j++)
			{
				num[j] = k % N;
				k /= N;
				b2[num[j]] = 1;
			}
			j = 0;
			while (b2[j]) j++;
			k = j+1;
			while (k < 8)
			{
				if (b2[k]) break;
				k++;
			}
			if (k < 8) continue;
			//We got a try of j colors
			int l;
			char flag = 1;
			for (l = 0; l < cc; l++)
			{
				memset(b2,0,sizeof(b2));
				for (k = 0; k < c[l].cnt; k++)
				{
					b2[num[c[l].a[k]]] = 1;
				}
				k = 0;
				while (k < j)
				{
					if (b2[k] == 0) break;
					k++;
				}
				if (k != j)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				if (j > res)
				{
					res = j;
					memcpy(resw,num,sizeof(num));
					if (res == totalmin) break;
				}
			}
		}
		printf("Case #%d: %d\n",iT+1,res);
		for (i = 0; i < N; i++)
		{
			if (i) printf(" ");
			printf("%d",resw[i]+1);
		}
		printf("\n");
	}
	return 0;
}

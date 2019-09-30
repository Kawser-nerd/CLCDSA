/* C */

#include <stdio.h>
#include <string.h>

char map[600][600];
char vis[600][600];

int chess[520];

char can (int i, int j, int maxi)
{
	int a, b, h=i+maxi, g=j+maxi;

	for (a=i; a<h; ++a)
		for (b=j; b<g; ++b)
		{
			if (a!=i && j==b)
				if (map[a-1][j] == map[a][j])
					return 0;
			if (b>j)
				if (map[a][b-1] == map[a][b])
					return 0;
			if (vis[a][b])
				return 0;
		}

	return 1;
}

void fill (int i, int j, int maxi)
{
	int a, b, h=i+maxi, g=j+maxi;

	for (a=i; a<h; ++a)
		for (b=j; b<g; ++b)
			vis[a][b] = 1;
}

main ()
{
	int T, t=0, M, N, i, k, j, maxi, res, flag;

	char c;

	scanf("%d", &T);

	while (t++<T)
	{
		scanf("%d%d\n", &M, &N);

		maxi = N < M ? N : M;

		res = 0;

		for (i=0; i<M; ++i, getchar())
			for (j=0; j<N; )
			{
				c = getchar();

				if (c>='0' && c<='9')
					k = c-'0';
				else
					k = c-'A'+10;
				map[i][j++] = k & 8 ? 1 : 0;
				map[i][j++] = k & 4 ? 1 : 0;
				map[i][j++] = k & 2 ? 1 : 0;
				map[i][j++] = k & 1 ? 1 : 0;
			}

		/*for (i=0; i<M; ++i, putchar('\n'))
			for (j=0; j<N; ++j)
				putchar(map[i][j] ? '*' : '_');*/

		bzero(vis, sizeof(vis));
		bzero(chess, sizeof(chess));

		printf("Case #%d: ", t);

		for (; maxi > 0; --maxi, res += flag)
		{
			flag = 0;
			for (i=0; i<M-maxi+1; ++i)
				for (j=0; j<N-maxi+1; ++j)
					if (can(i, j, maxi))
					{
						++chess[maxi];
						flag = 1;
						fill(i,j,maxi);
					}
		}

		printf("%d\n", res);

		for (i=519; i>0; --i)
			if (chess[i])
				printf("%d %d\n", i, chess[i]);
	}

	return 0;
}


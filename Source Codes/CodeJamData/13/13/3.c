#include <stdio.h>
#include <string.h>

int N, M, R, K;

int values[10000][20];
int ans[10000][20];
int find[10000];

int cur[20];

int assemble( int p)
{
	int i, j;
	for ( i = 0; i < ( 1 << N); i++)
	{
		int now = 1;
		for ( j = 0; j < 3; j++)
		{
			if ( i & ( 1 << j))
			{
				now *= cur[j];
			}
		}
		if ( p == now)
		{
			return 1;
		}
	}

	return 0;
}

void search( int deep)
{
	if ( deep == N)
	{
		int i, j;
		for ( i = 0; i < R; i++)
		{
			if ( !find[i])
			{
				find[i] = 1;
				for ( j = 0; j < K && find[i]; j++)
				{
					find[i] = assemble( values[i][j]);
				}
				if ( find[i])
				{
					/*
					printf("%d\n", i);
					int k;
					for ( k = 0; k < N; k++)
					{
						printf("%d", cur[k]);
					}
					printf("\n");
					*/

					memcpy( ans[i], cur, sizeof( cur));
				}
			}
		}
		return;
	}

	int i;
	for ( i = 2; i <= M; i++)
	{
		cur[deep] = i;
		search( deep + 1);
	}
}


int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d %d %d %d", &R, &N, &M, &K);
		int i, j;
		for ( i = 0; i < R; i++)
		{
			for ( j = 0; j < K; j++)
			{
				scanf("%d", &values[i][j]);
			}
		}

		memset( find, 0, sizeof( find));
		search( 0);
		printf("Case #%d:\n", cases + 1);
		for ( i = 0; i < R; i++)
		{
			for ( j = 0; j < N; j++)
			{
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}


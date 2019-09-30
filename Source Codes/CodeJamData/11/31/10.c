#include <stdio.h>
#include <string.h>

#define MAXL 50

char graph[MAXL][MAXL];
int use[MAXL];
int dp[MAXL];
int R, C;


/*
int aval( int p)
{
	int ret = -1;
	int j;
	for ( j = 0; j < C && ret; j++)
	{
		while ( j < C && graph[p][j] != '#')
		{
			++j;
		}
		if ( j < C)
		{
			ret = ( p && j != C - 1
				&& graph[p-1][j] == '#' 
				&& graph[p-1][j+1] == '#'
				&& graph[p][j+1] == '#'
				) ? 1 : 0;
		}
		++j;
	}
	
	return ret;
}
*/

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		scanf("%d %d", &R, &C);
		int i, j;
		for ( i = 0; i < R; i++)
		{
			char input[MAXL+1];
			scanf("%s", input);
			for ( j = 0; j < C; j++)
			{
				graph[i][j] = input[j];
			}
			/*
			use[i] = aval( i);
			*/
		}

		/*
		for ( i = 0; i < R; i++)
		{
			dp[i] = 0;
			if ( use[i])
			{
				if ( use[i] == -1)
				{
					dp[i] = i ? dp[i-1] : 1;
				}
				else
				{
					dp[i] = i > 1 ? dp[i-2] : 1;
				}
			}
		}
		*/

		int ans = 1;
		for ( i = 0; i < R && ans; i++)
		{
			for ( j = 0; j < C && ans; j++)
			{
				if ( graph[i][j] == '#')
				{
					ans &= i != R - 1 && j != C - 1 
						&& graph[i][j+1] == '#'
						&& graph[i+1][j] == '#'
						&& graph[i+1][j+1] == '#';
					if ( ans)
					{
						graph[i][j]='/';
						graph[i+1][j] = '\\';
						graph[i][j+1] = '\\';
						graph[i+1][j+1] = '/';
					}
				}
			}
		}


		printf("Case #%d:\n", cases + 1);
		if ( ans)
		{
			/*
			for ( i = R; i; i--)
			{
				if ( use[i-1] == 1)
				{
					for ( j = 0; j < C; j++)
					{
						while ( j < C && graph[i-1][j] != '#')
						{
							++j;
						}
						graph[i-2][j]='/';
						graph[i-1][j] = '\\';
						graph[i-2][j+1] = '\\';
						graph[i-1][j+1] = '/';
						++j;
					}
					--i;
				}
			}
			*/
			for ( i = 0; i < R; i++)
			{
				for ( j = 0; j < C; j++)
				{
					printf("%c", graph[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}

	return 0;
}



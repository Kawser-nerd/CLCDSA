#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int r, c;
char grid[MAX_N][MAX_N];
		
int solve()
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (grid[i][j] == '#')
			{
				if (i == r - 1 || j == c - 1)
					return 0;
				if (
				grid[i][j + 1] != '#' ||
				grid[i + 1][j] != '#' ||
				grid[i + 1][j + 1] != '#'
				)
					return 0;
				grid[i][j] = '/';
				grid[i][j + 1] = '\\';
				grid[i + 1][j] = '\\';
				grid[i + 1][j + 1] = '/';
			}
	for (i = 0; i < r; i++)
		printf("%s\n", grid[i]);

	return 1;
}

int main()
{
	int t, t_case;
	scanf("%d", &t_case);
	for (t = 1; t <= t_case; t++)
	{
		int i;
		scanf("%d %d", &r, &c);
		for (i = 0; i < r; i++)
			scanf("%s", grid[i]);
			
		printf("Case #%d:\n", t); 
		if (!solve())
			printf("Impossible\n");	
	}
	return 0;
}

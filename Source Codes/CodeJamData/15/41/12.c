#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int look_direction(char grid[][200], int nr, int nc, int r, int c, char dir)
{
	switch (dir)
	{
	case '^':
		for (r--; r >= 0; r--)
			if (grid[r][c] != '.')
				return 1;
		break;
	case '>':
		for (c++; c < nc; c++)
			if (grid[r][c] != '.')
				return 1;
		break;
	case 'v':
		for (r++; r < nr; r++)
			if (grid[r][c] != '.')
				return 1;
		break;
	case '<':
		for (c--; c >= 0; c--)
			if (grid[r][c] != '.')
				return 1;
		break;
	default:
		return 1;
	}

	return 0;
}

void do_test(int t)
{
	char grid[200][200];
	int r, c;
	int i, j;
	int answer = 0;

	scanf(" %d %d", &r, &c);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf(" %c", &grid[i][j]);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			if (look_direction(grid, r, c, i, j, grid[i][j]))
				continue;

			if (look_direction(grid, r, c, i, j, '^') ||
				look_direction(grid, r, c, i, j, '>') ||
				look_direction(grid, r, c, i, j, 'v') ||
				look_direction(grid, r, c, i, j, '<'))
				answer++;
			else
				goto impossible;
		}
				
	printf("Case #%d: %d\n", t + 1, answer);
	return;

impossible:
	printf("Case #%d: IMPOSSIBLE\n", t + 1);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}

#include<stdio.h>
#include <cmath>
#include <set>
int main()
{
	int rows, cols;
	int n, m, k;
	int grid[100][100];
	
	while (scanf("%d%d%d", &rows, &cols, &n) != EOF)
	{
		memset(grid, 0, sizeof(grid));k = -1;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			while (m--)
			{
				++k;
				grid[(k / rows) & 1 ? (rows - 1 - (k%rows)):k%rows][k / rows] = i;
			}
		}
		for (int i = 0; i<rows;++i)
			for (int j = 0; j<cols;++j)
				printf("%d%c",grid[i][j],j==cols-1?'\n':' ');
	}
	return 0;
}
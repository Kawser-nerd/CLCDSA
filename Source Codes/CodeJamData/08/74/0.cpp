#include <stdlib.h>
#include <stdio.h>

int states[70000][4][4];	// 2^16*16 states needed
int map[20][20];

int dX[8] = {1,1,1,0,0,-1,-1,-1};
int dY[8] = {1,0,-1,1,-1,1,0,-1};
int numCase, row, col;

bool isValid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < row && y < col)
		return true;
	else
		return false;
}

int search(int stateN, int sx, int sy)
{	// 0 for losing position, 1 for winning position
	if (states[stateN][sx][sy] != -1)
		return states[stateN][sx][sy];

	int dir;
	int overAll = 0;
	for (dir = 0; dir < 8; dir++)
	{
		int nx = sx + dX[dir];
		int ny = sy + dY[dir];
		if (isValid(nx, ny) && map[nx][ny] == 1 && (stateN & (1<<(nx*col+ny))) == 0)
		{
			int ans = search(stateN + (1<<(nx*col+ny)), nx, ny);
			if (ans == 0)
				overAll = 1;
		}
	}
	states[stateN][sx][sy] = overAll;
	return overAll;
}

int main()
{
	int i, j, k, l;
	int sx, sy;
	scanf("%d", &numCase);
	char aline[20];
	for (i = 0; i < numCase; i++)
	{
		scanf("%d %d", &row, &col);
		for (j = 0; j < row; j++)
		{
			scanf("%s", aline);
			for (k = 0; k < col; k++)
			{
				if (aline[k] == '#')
					map[j][k] = 0;
				else
					map[j][k] = 1;
				if (aline[k] == 'K')
				{
					sx = j;
					sy = k;
				}
			}
		}
		int nMax = (1 << (row * col));
		for (j = 0; j < nMax; j++)
			for (k = 0; k < 4; k++)
				for (l = 0; l < 4; l++)
					states[j][k][l] = -1;
					
		int ans = search((1<<(sx*col+sy)), sx, sy);
		printf("Case #%d: ", i+1);
		if (ans == 0)
			printf("B\n");
		else
			printf("A\n");
	}
	return 0;
}

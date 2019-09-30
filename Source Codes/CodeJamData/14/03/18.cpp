/* 2014.4.12 Yoshi-TS4 */

#include <stdio.h>
#include <map>

int poss[51][51][2501];
char map[51][51];

void prep()
{
	for (int i = 2; i <= 50; i++)
	{
		for (int j = 2; j <= 50; j++)
		{
			for (int k = 0; k <= i * j; k++)
				poss[i][j][k] = 0;
			for (int k = 2; k <= i; k++)
				for (int l = 2; l <= j; l++)
				{
					for (int m = k * l; m >= 2 * (k + l) - 4; m--)
					{
						if (!poss[i][j][m])
							poss[i][j][m] = 100 * k + l;
					}
				}
		}
	}
}

void create_map(int R, int C, int y, int x, int V)
{
	for (int i = 0; i < R; i++)
	for (int j = 0; j < C; j++)
	{
		map[i][j] = '*';
	}
	for (int i = 0; i < x; i++)
		map[0][i] = map[1][i] = '.';
	for (int i = 0; i < y; i++)
		map[i][0] = map[i][1] = '.';
	V -= 2 * (x + y) - 4;

	for (int i = 2; i < y; i++)
	for (int j = 2; j < x; j++)
	{
		if (V-- == 0) return;
		map[i][j] = '.';
	}
}

int main()
{
	prep();

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int R, C, M;

		fscanf(fin, "%d%d%d", &R, &C, &M);

		int V = R * C - M;

		if (R == 1)
		{
			for (int i = 0; i < C; i++)
			{
				map[0][i] = '*';
			}
			for (int i = 0; i < V; i++)
				map[0][i] = '.';
		}
		else if (C == 1)
		{
			for (int i = 0; i < R; i++)
			{
				map[i][0] = '*';
			}
			for (int i = 0; i < V; i++)
				map[i][0] = '.';
		}
		else
		{
			if (V == 1)
			{
				for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					map[i][j] = '*';
			}
			else
			{
				if (poss[R][C][V] == 0)
					goto hell;
				int y = poss[R][C][V] / 100;
				int x = poss[R][C][V] % 100;
				create_map(R, C, y, x, V);
			}
		}

		fprintf(fout, "Case #%d:\n", c_n);
		map[0][0] = 'c';
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				fprintf(fout, "%c", map[i][j]);
			fprintf(fout, "\n");
		}
		continue;

	hell:
		fprintf(fout, "Case #%d:\nImpossible\n", c_n);
	}

	return -0;
}
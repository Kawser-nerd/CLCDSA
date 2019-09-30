#include <stdio.h>

char buf[100][101];
int inf[100][101];

int I, J;

int get_dir (char x)
{
	switch (x)
	{
	case '^': return 1;
	case '>': return 2;
	case 'v': return 3;
	case '<': return 4;
	}

	return 0;
}

int move (int dir)
{
	switch (dir)
	{
	case 1: I--; break;
	case 2: J++; break;
	case 3: I++; break;
	case 4: J--; break;
	}
}

int main (void)
{
	int T, t, R, C, i, j, x, y, d;

	int dir, cnt;
	int ci, cj, bi, bj;

	scanf ("%d", &T);

	for (t = 1; t <= T; t++)
	{
		cnt = 0;

		scanf ("%d %d", &R, &C);

		for (i = 0; i < R; i++)
		{
			scanf ("%s", buf[i]);

			for (j = 0; j < C; j++)
				inf[i][j] = 0;
		}

		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				if (buf[i][j] != '.')
				{
					if (inf[i][j]) continue;

					I = i; J = j;
					ci = i; cj = j;
					bi = -1; bj = -1;
					inf[i][j] = 1;

					dir = get_dir (buf[i][j]);

					do
					{
						move (dir);

						if (I < 0 || I >= R || J < 0 || J >= C)
						{
							if (bi < 0)
							{
								d = 0;

								for (x = ci, y = 0; y < C; y++)
								{
									if (buf[x][y] != '.')
										d++;
								}

								for (x = 0, y = cj; x < R; x++)
								{
									if (buf[x][y] != '.')
										d++;
								}

								if (d == 2)
								{
									cnt = -1;
									break;
								}
								else
								{
									cnt++;
									break;
								}
							}
							else
							{
								cnt++;
								break;
							}
						}
						else
						{
							d = get_dir (buf[I][J]);

							if (d > 0)
							{
								if (inf[I][J])
									break;

								dir = d;
								bi = ci; bj = cj;
								ci = I;  cj = J;

								inf[I][J] = 1;
							}
						}
					}
					while (1);

					if (cnt < 0)
						break;
				}
			}

			if (cnt < 0)
				break;
		}

		if (cnt < 0)
			printf ("Case #%d: IMPOSSIBLE\n", t);
		else
			printf ("Case #%d: %d\n", t, cnt);
	}

	return 0;
}

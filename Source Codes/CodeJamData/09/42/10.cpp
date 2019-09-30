#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

const int MANY = 0x7F7F7F7F;
const int MAXRC = 50;

int r, c, f;
char ma[MAXRC + 1][MAXRC];

void Load()
{
	scanf("%d%d%d", &r, &c, &f);
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			char c = getchar();
			while (! ((c == '.') || (c == '#'))) c = getchar();
			ma[i][j] = c;
		}
	}
	for (j = 0; j < c; j++) ma[r][j] = '#';
}

int dst[MAXRC][MAXRC][MAXRC][MAXRC];

void Solve()
{
	memset(dst, 0x7F, sizeof(dst));
	dst[0][0][0][0] = 0;
	int i, j, j1, j2, q, lq, rq, nj1, nj2;
	for (i = 0; i < r - 1; i++)
	{
		for (j = 0; j < c; j++)
		{
			for (j1 = 0; j1 < c; j1++)
			{
				for (j2 = j1; j2 < c; j2++)
				{
					if (dst[i][j][j1][j2] == MANY) continue;
					//cerr << "Processing state: " << i << " " << j << " " << j1 << " " << j2 << "\n";
					int cr = dst[i][j][j1][j2];
					lq = rq = j;
					// just go left and fall
					for (q = j - 1; q >= 0; q--)
					{
						if (ma[i][q] == '#' && (q < j1 || q > j2)) break;
						if (ma[i + 1][q] == '.')
						{
							int nr = i + 1;
							while (ma[nr + 1][q] == '.') nr++;
							if (nr - i <= f)
							{
								//cerr << "Relaxed " << nr << " " << q << " " << q << " " << q << "\n";
								if (dst[nr][q][q][q] > cr)
								{
									dst[nr][q][q][q] = cr;
								}
							}
							break;
						}
						lq = q;
					}
					// just go right and fall
					for (q = j + 1; q < c; q++)
					{
						if (ma[i][q] == '#' && (q < j1 || q > j2)) break;
						if (ma[i + 1][q] == '.')
						{
							int nr = i + 1;
							while (ma[nr + 1][q] == '.') nr++;
							if (nr - i <= f)
							{
								//cerr << "Relaxed " << nr << " " << q << " " << q << " " << q << "\n";
								if (dst[nr][q][q][q] > cr)
								{
									dst[nr][q][q][q] = cr;
								}
							}
							break;
						}
						rq = q;
					}
					//cerr << "Got lq = " << lq << " rq = " << rq << "\n";
					// we can go through lq-rq
					for (nj1 = lq; nj1 <= rq; nj1++)
					{
						for (nj2 = nj1; nj2 <= rq; nj2++)
						{
							// go from left
							int nextr = cr + nj2 - nj1 + 1;
							if (nj1 != lq)
							{
								int ni = i + 1;
								while (ma[ni + 1][nj1] == '.') ni++;
								//cerr << "Go from left have " << ni << " " << nj1 << " " << nj2 << " " << "\n";
								if (ni - i <= f)
								{
									if (ni == i + 1)
									{
										if (dst[ni][nj1][nj1][nj2] > nextr)
										{
											dst[ni][nj1][nj1][nj2] = nextr;
										}
									}
									else
									{
										if (dst[ni][nj1][nj1][nj1] > nextr)
										{
											dst[ni][nj1][nj1][nj1] = nextr;
										}
									}
								}
							}
							// go from right
							if (nj2 != rq)
							{
								int ni = i + 1;
								while (ma[ni + 1][nj2] == '.') ni++;
								//cerr << "Go from right have " << ni << " " << nj1 << " " << nj2 << " " << "\n";
								if (ni - i <= f)
								{
									if (ni == i + 1)
									{
										if (dst[ni][nj2][nj1][nj2] > nextr)
										{
											dst[ni][nj2][nj1][nj2] = nextr;
										}
									}
									else
									{
										if (dst[ni][nj2][nj2][nj2] > nextr)
										{
											dst[ni][nj2][nj2][nj2] = nextr;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int mans = MANY;
	for (j = 0; j < c; j++)
	{
		for (j1 = 0; j1 < c; j1++)
		{
			for (j2 = j1; j2 < c; j2++)
			{
				if (dst[r - 1][j][j1][j2] < mans)
				{
					mans = dst[r - 1][j][j1][j2];
				}
			}
		}
	}
	if (mans == MANY) printf("No");
	else printf("Yes %d", mans);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
		cerr << "Processed case " << it + 1 << "\n";
	}
	return 0;
}
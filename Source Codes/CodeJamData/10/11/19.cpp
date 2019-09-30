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

int n, k;
char ma[110][110];

void Load()
{
	scanf("%d%d", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			char c = getchar();
			while (! ((c ==  '.') || (c == 'R') || (c == 'B'))) c = getchar();
			ma[i][j] = c;
		}
	}
}

int nma[110][110];
const int di[4] = {-1, 0, -1, -1};
const int dj[4] = {0, 1, 1, -1};

void Solve()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			nma[j][n - 1 - i] = ma[i][j];
		}
	}
	for (j = 0; j < n; j++)
	{
		int q = n - 1;
		for (i = n - 1; i >= 0; i--)
		{
			if (nma[i][j] != '.')
			{
				nma[q][j] = nma[i][j];
				q--;
			}	
		}
		while (q >= 0)
		{
			nma[q][j] = '.';
			q--;
		}
	}
/*	cerr << "Field:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) cerr << (char)nma[i][j];
		cerr << "\n";
	}*/
	int hr, hb;
	hb = hr = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			int dr;
			for (dr = 0; dr < 4; dr++)
			{
				int fr, fb;
				fr = fb = 1;
				int p;
				for (p = 0; p < k; p++)
				{
					int ni, nj;
					ni = i + di[dr] * p;
					nj = j + dj[dr] * p;
					if (ni < 0 || ni >= n || nj < 0 || nj >= n)
					{
						fr = fb = 0;
					}
					else
					{
						if (nma[ni][nj] != 'R') fr = 0;
						if (nma[ni][nj] != 'B') fb = 0;
					}
				}
				if (fr) hr = 1;
				if (fb) hb = 1;
			}
		}
	}
	if (hr == 1 && hb == 1) printf("Both");
	else if (hr == 1) printf("Red");
	else if (hb == 1) printf("Blue");
	else printf("Neither");
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
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int n, m;
char ma[51][51];

void Load()
{
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			char c = getchar();
			while (! ((c == '.') || (c == '#') || (c == '?'))) c = getchar();
			ma[i][j] = c;
		}
	}
}

int res[16][15][65536];

int Set0(int a, int i)
{
	return a & (~ (1 << i));
}

int Set1(int a, int i)
{
	return a | (1 << i);
}

int Get(int a, int i)
{
	if ((a & (1 << i)) != 0) return 1;
	else return 0;
}

void Solve()
{
	memset(res, 0, sizeof(res));
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			int ni = i;
            int nj = j + 1;
            if (nj == m)			
            {
            	ni++;
            	nj = 0;
            }
			for (k = 0; k < (1 << m); k++)
			{
				if (ma[i][j] == '.')
				{
					int nk = Set0(k, j);
					if (res[ni][nj][nk] < res[i][j][k]) res[ni][nj][nk] = res[i][j][k];
				}
				else if (ma[i][j] == '#')
				{
					int tadd = 2;
					if (Get(k, j) == 0) tadd++;
					else tadd--;
					if ((j != 0) && (Get(k, j - 1) == 0)) tadd++;
					else if (j != 0) tadd--;
					else tadd++;
					int nk = Set1(k, j);
					if (res[ni][nj][nk] < res[i][j][k] + tadd) res[ni][nj][nk] = res[i][j][k] + tadd;
				}
				else
				{
					// place '.'
					int nk = Set0(k, j);
					if (res[ni][nj][nk] < res[i][j][k]) res[ni][nj][nk] = res[i][j][k];
					// place '#'
					int tadd = 2;
					if (Get(k, j) == 0) tadd++;
					else tadd--;
					if ((j != 0) && (Get(k, j - 1) == 0)) tadd++;
					else if (j != 0) tadd--;
					else tadd++;
					nk = Set1(k, j);
					if (res[ni][nj][nk] < res[i][j][k] + tadd) res[ni][nj][nk] = res[i][j][k] + tadd;
				}
			}
		}
	}            
	int ans = 0;
	for (k = 0; k < (1 << m); k++) ans = max(ans, res[n][0][k]);
	cout << ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		cerr << it << "\n";
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}
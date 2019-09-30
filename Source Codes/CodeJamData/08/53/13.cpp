#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

#pragma comment (linker, "/STACK:20000000")

int n, m;
char ma[100][100];

void Load()
{
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			char c = getchar();
			while (! ((c == '.') || (c == 'x')) ) c = getchar();
			ma[i][j] = c;
		}
	}
}

const int dj[6] = {1, 1, -1, -1, -1, 1};
const int di[6] = {-1, 0, -1, 0, 1, 1};
             
int was[110][110];
int match[110][110][2];

int Dfs(int i, int j)
{
	was[i][j] = 1;
	int k;
	for (k = 0; k < 6; k++)
	{
		int ni = i + di[k];
		int nj = j + dj[k];
		if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;
		if (ma[ni][nj] == 'x') continue;
		if (match[ni][nj][0] == -1)
		{
			match[ni][nj][0] = i;
			match[ni][nj][1] = j;
			return 1;
		}
		else if (was[match[ni][nj][0]][match[ni][nj][1]] == 0)
		{
			if (Dfs(match[ni][nj][0], match[ni][nj][1]))
			{
				match[ni][nj][0] = i;
				match[ni][nj][1] = j;
				return 1;
			}
		}
	}
	return 0;
}

void Solve()
{
	int i, j, ii, jj;
	int ans = 0;
	int nall = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (ma[i][j] != 'x') nall++;
			match[i][j][0] = match[i][j][1] = -1;
		}
	}            
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (j % 2 == 1) continue;
			if (ma[i][j] == 'x') continue;
			for (ii = 0; ii < n; ii++)
			{
				for (jj = 0; jj < m; jj++)
				{
					was[ii][jj] = 0;
				}
			}
			if (Dfs(i, j)) ans++;
		}
	}
	cerr << "ans = " << ans << "\n";
	cout << nall - ans;
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
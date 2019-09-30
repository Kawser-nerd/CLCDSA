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
int prc[100][25];

void Load()
{
	scanf("%d%d", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			scanf("%d", &prc[i][j]);
		}
	}
}

int ma[100][100];
int was[100];
int match[100];

int Dfs(int v)
{
	int i;
	was[v] = 1;
	for (i = 0; i < n; i++)
	{
		if (ma[v][i] == 0) continue;
		if (match[i] == -1)
		{
			match[i] = v;
			return 1;
		}
		else
		{
			if (was[match[i]] == 0)
			{
				if (Dfs(match[i]))
				{
					match[i] = v;
					return 1;
				}
			}
		}
	}
	return 0;
}

void Solve()
{
	memset(ma, 0, sizeof(ma));
	int i, j, q;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == i) continue;
			int f = 1;
			for (q = 0; q < k; q++)
			{
				if (prc[j][q] <= prc[i][q])
				{
					f = 0;
					break;
				}
			}
			ma[i][j] = f;
		}
	}
	memset(match, 0xFF, sizeof(match));
	int nm = 0;
	for (i = 0; i < n; i++)
	{
		memset(was, 0, sizeof(was));
		if (Dfs(i)) nm++;	
	}
	printf("%d", n - nm);
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
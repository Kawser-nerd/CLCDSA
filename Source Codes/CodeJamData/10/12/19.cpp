#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int cd, ci, m, n;
int a[110];

void Load()
{
	scanf("%d%d%d%d", &cd, &ci, &m, &n);
	int i;
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
}

int res[110][256];

void Solve()
{
	memset(res, 0x7F, sizeof(res));
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 256; j++)
		{
			res[i][j] = cd * i + abs(a[i] - j);
		}
	}
	for (i = 0; i < n; i++)
	{
		// insert
		int k;
		for (j = 0; j < 256; j++)
		{
			if (res[i][j] == 0x7F7F7F7F) continue;
			for (k = 0; k < 256; k++)
			{
				if (abs(k - j) <= m)
				{
					if (res[i][k] > res[i][j] + ci)
					{
						res[i][k] = res[i][j] + ci;
					}
				}
			}
			for (k = 255; k >= 0; k--)
			{
				if (abs(k - j) <= m)
				{
					if (res[i][k] > res[i][j] + ci)
					{
						res[i][k] = res[i][j] + ci;
					}
				}
			}
		}
		for (j = 255; j >= 0; j--)
		{
			if (res[i][j] == 0x7F7F7F7F) continue;
			for (k = 0; k < 256; k++)
			{
				if (abs(k - j) <= m)
				{
					if (res[i][k] > res[i][j] + ci)
					{
						res[i][k] = res[i][j] + ci;
					}
				}
			}
			for (k = 255; k >= 0; k--)
			{
				if (abs(k - j) <= m)
				{
					if (res[i][k] > res[i][j] + ci)
					{
						res[i][k] = res[i][j] + ci;
					}
				}
			}
		}
		//cerr << "i = " << i << "\n";
		//for (j = 0; j <= 50; j++) cerr << res[i][j] << " ";
		//cerr << "\n";
		for (j = 0; j < 256; j++)
		{
			if (res[i][j] == 0x7F7F7F7F) continue;
			// delete
			if (res[i + 1][j] > res[i][j] + cd) res[i + 1][j] = res[i][j] + cd;
			// take
			for (k = 0; k < 256; k++)
			{
			
				if (abs(j - k) <= m)
				{
					if (res[i + 1][k] > res[i][j] + abs(a[i + 1] - k))
					{
						res[i + 1][k] = res[i][j] + abs(a[i + 1] - k);
					}
				}
			}
		}
	}
	int ans = cd * n;
	for (j = 0; j < 256; j++)
	{
		if (res[n - 1][j] < ans) ans = res[n - 1][j];
	}
	printf("%d", ans);
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
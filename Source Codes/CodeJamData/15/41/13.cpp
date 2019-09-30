#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
char a[N][N];
int n, m;

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
const char DD[] = "v>^<";

bool checkPos(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool checkDir(int dir, int x, int y)
{
	x += DX[dir], y += DY[dir];
	while(checkPos(x, y) && a[x][y] == '.')
	{
		x += DX[dir];
		y += DY[dir];
	}
	return checkPos(x, y);
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", a[i]);
	int ans = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			if (a[x][y] == '.') continue;
			int dir = 0;
			while(DD[dir] != a[x][y]) dir++;
			if (checkDir(dir, x, y)) continue;
			ans++;
			bool ok = false;
			for (int i = 0; i < 4; i++)
				if (checkDir(i, x, y))
				{
					ok = true;
					break;
				}
			if (!ok)
			{
				printf("IMPOSSIBLE\n");
				return;
			}
		}
	printf("%d\n", ans);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}

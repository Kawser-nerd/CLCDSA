#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

const int di[2] = {2, 1};
const int dj[2] = {1, 2};
const int MOD = 10007;

int w, h, r;
int ma[110][110];

void Load()
{
	memset(ma, 0, sizeof(ma));
	scanf("%d%d%d", &h, &w, &r);
	int i;
	for (i = 0; i < r; i++)
	{
		int cr, cc;
		scanf("%d%d", &cr, &cc);
		ma[cr][cc] = 1;
	}
}

int res[110][110];

void Solve()
{
	memset(res, 0, sizeof(res));
	res[1][1] = 1;
	int i, j;
	for (i = 1; i <= h; i++)
	{
		for (j = 1; j <= w; j++)
		{
			int k;
			for (k = 0; k < 2; k++)
			{
				if (ma[i + di[k]][j + dj[k]] == 1) continue;
				if (ma[i][j] == 1) continue;
				if (res[i][j] == 0) continue;
				res[i + di[k]][j + dj[k]] += res[i][j];
				res[i + di[k]][j + dj[k]] %= MOD;
			}
		}
	}
	cout << res[h][w];
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
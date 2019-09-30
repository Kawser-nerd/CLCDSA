#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int r, c;
int num[50][50];


void Load()
{
	scanf("%d%d", &r, &c);
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &num[i][j]);
		}
	}
}

const int di[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dj[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int f[5][5];
int oans;

void Check()
{
	int i, j;
	int nm = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			int cn = 0;
			int k, nr, nc;
			for (k = 0; k < 9; k++)
			{
				nr = i + di[k];
				nc = j + dj[k];
				if ((nr < 0) || (nr >= r) || (nc < 0) || (nc >= c)) continue;
				if (f[nr][nc] == 1) cn++;
			}
			if (cn != num[i][j]) return;
			if (i == r / 2)
			{
				if (f[i][j] == 1) nm++;
			}
		}
	}
	oans = max(oans, nm);
}

void Solve()
{
	oans = 0;
	int i;
	for (i = 0; i < (1 << (r * c)); i++)
	{
		int ci, cj;
		ci = cj = 0;
		memset(f, 0, sizeof(f));
		int k;
		for (k = 0; k < r * c; k++)
		{
			if ((i & (1 << k)) != 0)
			{
				f[ci][cj] = 1;
			}
			cj++;
			if (cj == c)
			{
				ci++;
				cj = 0;
			}
		}
		Check();
	}
	cout << oans;
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
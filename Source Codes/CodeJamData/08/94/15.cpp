#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, m;
char ma[51][51];
int bi, bj, ei, ej;

void Load()
{
	scanf("%d%d", &n, &m);
	int i, j;
	bi = bj = 0;
	ei = ej = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			char c = getchar();
			while (! ((c == '.') || (c == '#') || (c == 'T'))) c = getchar();
			if (c == 'T')
			{
				if (! ((i == 0) && (j == 0)))
				{
					ei = i;
					ej = j;
				}
				c = '#';
			}
			ma[i][j] = c;
		}
	}
}

const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};
int go[51][51];
int dst[51][51];
int was[51][51];

void Solve()
{
	vector<pair<int, int> > q;
	q.clear();
	q.push_back(make_pair(bi, bj));
	memset(go, 0xFF, sizeof(go));
	int hd = 0;
	while (hd < q.size())
	{
		int k;
		for (k = 0; k < 4; k++)
		{
			int ni = q[hd].first + di[k];
			int nj = q[hd].second + dj[k];
			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;
			if (ma[ni][nj] == '.') continue;
			if (go[ni][nj] == -1)
			{
				go[ni][nj] = k;
				q.push_back(make_pair(ni, nj));
			}
		}
		hd++;
	}
	int res = 0;
	memset(dst, 0x7F, sizeof(dst));
	int ci, cj;
	ci = ei;
	cj = ej;
	q.clear();
	while (! ((ci == bi) && (cj == bj)))
	{
		q.push_back(make_pair(ci, cj));
		int k = go[ci][cj];
		ci -= di[k];
		cj -= dj[k];
	}
	q.push_back(make_pair(bi, bj));
	memset(was, 0, sizeof(was));
	int i;
	for (i = 0; i < q.size(); i++)
	{
		dst[q[i].first][q[i].second] = min(i, ((int)q.size()) - 1 - i);  
		int mi = q[i].first;
		int mj = q[i].second;
		was[mi][mj] = 1;
		int k;
		for (k = 0; k < 4; k++)
		{
			int ni = mi + di[k];
			int nj = mj + dj[k];
			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;
			if (ma[ni][nj] == '.') continue;
			if (dst[ni][nj] > dst[mi][mj] + 1)
			{
				dst[ni][nj] = dst[mi][mj] + 1;
			}
		}
		res += i;
	}
	while (1)
	{
		int j;
		int mi, mj;
		int md = 0x7F7F7F7F;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (ma[i][j] == '.') continue;
				if (was[i][j] != 0) continue;
				if (dst[i][j] < md)
				{
					md = dst[i][j];
					mi = i;
					mj = j;
				}
			}
		}
		if (md == 0x7F7F7F7F) break;
		was[mi][mj] = 1;
		res += dst[mi][mj];
		int k;
		for (k = 0; k < 4; k++)
		{
			int ni = mi + di[k];
			int nj = mj + dj[k];
			if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m)) continue;
			if (ma[ni][nj] == '.') continue;
			if (dst[ni][nj] > dst[mi][mj] + 1)
			{
				dst[ni][nj] = dst[mi][mj] + 1;
			}
		}
	}
	cout << res;
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
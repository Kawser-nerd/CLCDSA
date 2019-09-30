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

const int MEGAC = 1000;

int w, q;
char ma[20][20];

void Load()
{
	scanf("%d%d", &w, &q);
	int i, j;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < w; j++)
		{
			char c = getchar();
			while (! (((c >= '0' && (c <= '9')) || (c == '-') || (c == '+')))) c = getchar();
			ma[i][j] = c;
		}
	}
}

const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

int dst[20][20][2 * MEGAC + 1];
string rs[20][20][2 * MEGAC + 1];
int qu[20 * 20 * (2 * MEGAC + 1)][3];
int hd, tl;

void Solve()
{
	vector<int> qq;
	set<int> have;
	memset(dst, 0x7F, sizeof(dst));
	int i, j, k;
	for (i = 0; i < q; i++)
	{
		scanf("%d", &j);
		qq.push_back(j);
		have.insert(j);
	}
	hd = tl = 0;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (ma[i][j] >= '0' && ma[i][j] <= '9')
			{
				dst[i][j][ma[i][j] - '0' + MEGAC] = 1;
				rs[i][j][ma[i][j] - '0' + MEGAC] = ma[i][j];
				qu[tl][0] = i;
				qu[tl][1] = j;
				qu[tl][2] = ma[i][j] - '0' + MEGAC;
				tl++;
			}
		}
	}
	while (hd < tl)
	{
		int ci = qu[hd][0];
		int cj = qu[hd][1];
		int cr = qu[hd][2];
		have.erase(cr - MEGAC);
		if (have.size() == 0) break;
		int k2;
		for (k = 0; k < 4; k++)
		{
			int ti, tj;
			ti = ci + di[k];
			tj = cj + dj[k];
			if (ti < 0 || ti >= w || tj < 0 || tj >= w) continue;
			for (k2 = 0; k2 < 4; k2++)
			{
				int ni, nj;
				ni = ti + di[k2];
				nj = tj + dj[k2];
				if (ni < 0 || ni >= w || nj < 0 || nj >= w) continue;
				int nr = cr;
				if (ma[ti][tj] == '+') nr = cr + ma[ni][nj] - '0';
				else nr = cr - (ma[ni][nj] - '0');
				if (nr < 0 || nr > 2 * MEGAC) continue;
				if (dst[ni][nj][nr] > dst[ci][cj][cr] + 2)
				{
					dst[ni][nj][nr] = dst[ci][cj][cr] + 2;
					rs[ni][nj][nr] = rs[ci][cj][cr] + ma[ti][tj] + ma[ni][nj];
					qu[tl][0] = ni;
					qu[tl][1] = nj;
					qu[tl][2] = nr;
					tl++;
				}
				else if (dst[ni][nj][nr] == dst[ci][cj][cr] + 2)
				{
					string ts = rs[ci][cj][cr] + ma[ti][tj] + ma[ni][nj];
					if (rs[ni][nj][nr] > ts)
					{
						rs[ni][nj][nr] = ts;	
					}
				}
			}
		}
		hd++;
	}

	for (i = 0; i < q; i++)
	{
		int num = qq[i];
		int md = 2000000000;
		string ms = "";
		for (j = 0; j < w; j++)
		{
			for (k = 0; k < w; k++)
			{
				if (dst[j][k][num + MEGAC] < md || dst[j][k][num + MEGAC] == md && rs[j][k][num + MEGAC] < ms)
				{
					md = dst[j][k][num + MEGAC];
					ms = rs[j][k][num + MEGAC];
				}
			}
		}
		printf("%s\n", ms.c_str());
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d:\n", it + 1);
		Load();
		Solve();
		cerr << "ok " << it + 1 << "\n";
	}
	return 0;
}
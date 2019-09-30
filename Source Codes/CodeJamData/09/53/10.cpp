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

const int MAXY = 15;
const int MAXN = 100;

int n;
vector<pair<int, int> > men;

void Load()
{
	men.clear();
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		men.push_back(make_pair(p, q - 1));
	}
	sort(men.begin(), men.end());
	reverse(men.begin(), men.end());
}

set<int> pth[MAXN + 1];
int have[MAXY];
int c;

bool Can()
{
	if (c == 4) return true;
	memset(have, 0, sizeof(have));
	int i;
	for (i = 0; i <= n; i++) pth[i].clear();
	pth[0].insert(0);
	for (i = 0; i < n; i++)
	{
		set<int>::iterator p;
		for (p = pth[i].begin(); p != pth[i].end(); p++)
		{
			int cur = *p;
			int q, cc;
			for (cc = 0; cc < c; cc++)
			{
				int f = 1;
				for (q = men[i].second - 1; q <= men[i].second + 1; q++)
				{
					if (q < 0 || q >= MAXY) continue;
					if (!have[q]) continue;
					if (((cur >> (2 * q)) & 3) == cc)
					{
						f = 0;
						break;
					}
				}
				if (f)
				{
					int nv = cur & ~(3 << (2 * men[i].second));
					nv |= cc << (2 * men[i].second);
					pth[i + 1].insert(nv);
				}
			}
		}
		have[men[i].second] = 1;
	}
	if (pth[n].size() > 0) return true;
	return false;
}

void Solve()
{
	for (c = 1; c <= 4; c++)
	{
		if (Can())
		{
			cout << c;
			return;
		}
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
		cerr << it << "\n";
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}
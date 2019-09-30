#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int MAXCRD = 110;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

class Point 
{
public:
	int x, y;
};

vector<pair<Point, Point> > otr;

void ReadS(string &s)
{
	s = "";
	char c = getchar();
	while (! ((c == 'F') || (c == 'L') || (c == 'R'))) c = getchar();
	while ((c == 'F') || (c == 'L') || (c == 'R'))
	{
		s += c;
		c = getchar();
	}
}

void Load()
{
	otr.clear();
	int cd;
	Point cp;
	cp.x = cp.y = MAXCRD;
	cd = 0;
	int l;
	scanf("%d", &l);
	int i;
	for (i = 0; i < l; i++)
	{
		string ts;
		ReadS(ts);
		int t;
		scanf("%d", &t);
		int j;
		for (j = 0; j < t; j++)
		{
			int k;
			for (k = 0; k < ts.length(); k++)
			{
				if (ts[k] == 'F')
				{
					Point np;
					np.x = cp.x + dx[cd];
					np.y = cp.y + dy[cd];
					otr.push_back(make_pair(cp, np));
					cp = np;
				}
				else if (ts[k] == 'R')
				{
					cd++;
					cd %= 4;
				}
				else if (ts[k] == 'L')
				{
					cd += 3;
					cd %= 4;
				}
			}
		}
	}
}

vector<int> hseg[2 * MAXCRD];
vector<int> vseg[2 * MAXCRD];

int GetL(vector<int> &a, int val)
{
	if (a.size() == 0) return 0;
	int max = -1;
	int l, r;
	l = 0;
	r = a.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[mid] <= val)
		{
			if (mid > max) max = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return max + 1;
}

void Solve()
{
	int i, j;
	for (i = 0; i < 2 * MAXCRD; i++) hseg[i].clear();
	for (i = 0; i < 2 * MAXCRD; i++) vseg[i].clear();
	for (i = 0; i < otr.size(); i++)
	{
		if (otr[i].first.x == otr[i].second.x)
		{
			vseg[min(otr[i].first.y, otr[i].second.y)].push_back(otr[i].first.x);
		}
		else
		{
			hseg[min(otr[i].first.x, otr[i].second.x)].push_back(otr[i].first.y);
		}
	}
	for (i = 0; i < 2 * MAXCRD; i++)
	{
		if (hseg[i].size() > 0) sort(hseg[i].begin(), hseg[i].end());
		if (vseg[i].size() > 0) sort(vseg[i].begin(), vseg[i].end());
	}
	int ans = 0;
	for (i = 0; i < 2 * MAXCRD; i++)
	{
		for (j = 0; j < 2 * MAXCRD; j++)
		{
			int n1 = GetL(hseg[i], j);
			if ((n1 % 2 == 0) && (n1 > 0) && (n1 != hseg[i].size())) 
			{
				ans++;
				continue;
			}
			n1 = GetL(vseg[j], i);
			if ((n1 % 2 == 0) && (n1 > 0) && (n1 != vseg[j].size()))
			{
				ans++;
			}
		}
	}
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
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}
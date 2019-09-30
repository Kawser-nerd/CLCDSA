#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){ return x > 0 ? x : (-x); }
template<class T> T sqr(T x){ return x * x; }

string a[50];
int n;

map<int, string> d[22][22];
map<int, bool> u[22][22];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

bool good(int x, int y)
{
	return x >= 0 && x < n && y >=0 && y < n;
}

bool cmp(string s1, string s2)
{
	if (s1 == "") return true;
	if (s2 == "") return false;
	if (sz(s1) != sz(s2))
		return sz(s1) < sz(s2);
	return s1 < s2;
}

queue<pair<ii, int> > q;

void solve(int x, int y, int c)
{
	if (!d[x][y].count(c))
		d[x][y][c] = "";
	string cur = d[x][y][c];
	for (int d1 = 0; d1 < 4; d1++)
	{
		int x1 = x + dx[d1];
		int y1 = y + dy[d1];
		if (!good(x1, y1)) continue;
		int sg = a[x1][y1] == '-' ? (-1) : 1;
		for (int d2 = 0; d2 < 4; d2++)
		{
			int x2 = x1 + dx[d2];
			int y2 = y1 + dy[d2];
			if (!good(x2, y2)) continue;
			int tmp = a[x][y] - '0';
			tmp *= sg;
			string s;
			s += a[x1][y1];
			s += a[x][y];
			s += cur;
			{
				string& res = d[x2][y2][tmp + c];
				if (cmp(s, res))
					res = s;
				if (!u[x2][y2][tmp + c])
				{
					u[x2][y2][tmp + c] = true;
					q.push(mp(ii(x2, y2), tmp + c));
					res = s;
				}
			}
		}
	}
}

void solve(int testnum)
{
	printf("Case #%d:\n", testnum + 1);
	int Q;
	cin >> n >> Q;
	int BUBEN = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < n; j++)
			if (isdigit(a[i][j]))
				BUBEN += (a[i][j] - '0');
	}
	BUBEN = max(BUBEN, 300);
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 22; j++)
		{
			u[i][j].clear();
			d[i][j].clear();
		}
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (isdigit(a[i][j]))
			{
				q.push(mp(ii(i, j), 0));
				u[i][j][0] = true;
			}
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		q.pop();
		if (abs(c) > BUBEN) continue;
		solve(x, y, c);
	}
	for (int it = 0; it < Q; it++)
	{
		int x;
		cin >> x;
		string res = "";
		bool fn = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (isdigit(a[i][j]))
				{
					if (!u[i][j][x - int(a[i][j] - '0')]) continue;
					string s = d[i][j][x - int(a[i][j] - '0')];
//					if (s == "" && (x - int(a[i][j] - '0') != 0)) continue;
					reverse(all(s));
					s += a[i][j];
					reverse(all(s));
					if (s == "") continue;
					if (!fn || cmp(s, res) || res == "")
					{
						fn = true;
						res = s;
					}
				}
//		assert(res != "");
		cout << res << "\n";
	}
}

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; it++)
	{
		solve(it);
	}
	return 0;
}

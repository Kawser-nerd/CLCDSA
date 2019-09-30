#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef vector<int> VI;
typedef pair<int, int> pii;
typedef long long ll;

#define NMAX 505
#define INF 2000000009

int n;
map<string, int> num;
vector<pii> v[NMAX];

int getNum(string s)
{
	if (num.count(s) == 0)
	{
		num.insert(mp(s, num.size()));
	}
	return num[s];

}

int d[3 * NMAX];
vector<pii> v1;

int ans;

int coord[3 * NMAX];
int cc;
void solve(vector<pii>& v1)
{
	cc = 0;

	forv(i, v1)
	{
		coord[cc++] = v1[i].first - 1;
		coord[cc++] = v1[i].second;
	}	
	coord[cc++] = 0;
	coord[cc++] = 10000;
	sort(coord, coord + cc);
	cc = int(unique(coord, coord + cc) - coord);
	forv(i, v1)
	{
		v1[i].first = int(lower_bound(coord, coord + cc, v1[i].first - 1) - coord); 
		v1[i].second = int(lower_bound(coord, coord + cc, v1[i].second) - coord); 
	}
	sort(all(v1));
	forn(i, cc) d[i] = INF;
	d[0] = 0;
	forv(i, v1)
	{
		for (int j = v1[i].first; j < v1[i].second; j++)
		{
			if (d[j] == INF) continue;
			d[v1[i].second] = min(d[v1[i].second], d[j] + 1);
		}
	}
	ans = min(ans, d[cc - 1]);
}
void solve(int test)
{
	printf("Case #%d: ", test);

	num.clear();
	scanf("%d\n", &n);
	forn(i, n) v[i].clear();

	string col; int l, r;

	forn(i, n)
	{
		cin >> col >> l >> r;
		int id = getNum(col);
		v[id].pb(mp(l, r));
		
	}

	ans = INF;
	int m = num.size();
	forn(c1, m)
	{
		v1.clear();
		forv(i, v[c1]) v1.pb(v[c1][i]);
		solve(v1);															
		forn(c2, c1)
		{
			v1.clear();
			forv(i, v[c1]) v1.pb(v[c1][i]);
			forv(i, v[c2]) v1.pb(v[c2][i]);
			solve(v1);															
			forn(c3, c2)
			{
				v1.clear();
				forv(i, v[c1]) v1.pb(v[c1][i]);
				forv(i, v[c2]) v1.pb(v[c2][i]);
				forv(i, v[c3]) v1.pb(v[c3][i]);
				solve(v1);															
			}
		}
	}

	if (ans == INF)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << ans << endl;
	}
}
int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);

	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
         	


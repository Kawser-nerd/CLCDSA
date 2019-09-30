#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 218 * 218;
const int64 mod = 1000003;

vi g[maxn];

const int dx[] = {0, 1, 1, -1};
const int dy[] = {1, 0, 1, 1};

bool u[maxn];

int cntV, cntE;

void dfs(int x) {
	++cntV;
	u[x] = true;
	for (int i = 0; i < sz(g[x]); ++i) {
		++cntE;
		if (!u[g[x][i]]) dfs(g[x][i]);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < maxn; ++i)
		g[i].clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			char c = s[j];
			int dir;
			if (c == '-') dir = 0;
			else if (c == '|') dir = 1;
			else if (c == '\\') dir = 2;
			else if (c == '/') dir = 3;
			else cerr << "AAA\n";
			int x1, y1, x2, y2;
			x1 = (i + dx[dir] + n) % n;
			y1 = (j + dy[dir] + m) % m;
			x2 = (i - dx[dir] + n) % n;
			y2 = (j - dy[dir] + m) % m;
			g[x1 * 218 + y1].pb(x2 * 218 + y2);
			g[x2 * 218 + y2].pb(x1 * 218 + y1);
		}
	}
	int64 res = 1;
	memset(u, 0, sizeof(u));
	for (int i = 0; i < maxn; ++i)
		if (sz(g[i]) && !u[i]) {
			cntV = 0, cntE = 0;			
			dfs(i); 
			cntE /= 2;
			if (cntV == cntE) 
				res = (res * 2LL) % mod;
			else if (cntV == cntE + 1) {}
			else res = 0;
		}
	cout << res << "\n";
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}

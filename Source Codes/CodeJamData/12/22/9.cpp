#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) {
	return x > 0 ? x : -x;
}

int m;
int n;

int h;

int h1[240][240], h2[240][240];
int d[240][240];

bool l1(ii a, ii b) {
	if (d[a.fi][a.se] != d[b.fi][b.se])
		re d[a.fi][a.se] < d[b.fi][b.se];
	re a < b;
}

set<ii, bool (*) (ii, ii)> s(l1);

int check(int x, int y) {
	re x >= 0 && x < n && y >= 0 && y < m;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void parse(ii o, int f) {
	int x = o.fi;
	int y = o.se;
	int dd = d[x][y];
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check(nx, ny))
			continue;
		if (h1[x][y] >= 50 + h2[nx][ny])
		if (h2[x][y] <= h1[nx][ny] - 50)
		if (h2[nx][ny] <= h1[nx][ny] - 50) {
			int ch = h1[nx][ny] - 50;
			int oh = h - dd;
			int ct = 0;
			if (f)
				oh = h;
			if (oh > ch) {
				if (f)
					continue;
				ct = oh - ch;
				oh = ch;
			}
			if (oh - h2[x][y] >= 20)
				ct += 10;
			else
				ct += 100;

			if (d[nx][ny] == -1 || d[nx][ny] > ct + dd) {
				s.erase(mp(nx, ny));
				d[nx][ny] = ct + dd;
				s.insert(mp(nx, ny));
			}
		}
	}
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> h >> n >> m;
		rep(i, n) rep(j, m)
			cin >> h1[i][j];
		rep(i, n) rep(j, m)
			cin >> h2[i][j];

		fill(d, -1);
		d[0][0] = 0;
		s.insert(mp(0, 0));
		while (!s.empty()) {
			ii x = *s.begin();
			s.erase(x);
			parse(x, 1);
		}

		vii v;
		rep(i, n) rep(j, m)
			if (d[i][j] != -1)
				v.pb(mp(i, j));

		fill(d, -1);
		rep(i, sz(v)) {
			int x = v[i].fi;
			int y = v[i].se;
			d[x][y] = 0;
			s.insert(mp(x, y));
		}

		while (!s.empty()) {
			ii x = *s.begin();
			s.erase(x);
			parse(x, 0);
		}

		printf("%.1lf", d[n - 1][m - 1] / 10.0);
		cout << endl;
	}

	re 0;
}

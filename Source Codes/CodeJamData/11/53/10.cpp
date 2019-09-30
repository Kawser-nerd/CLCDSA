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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

int dx[100][100];
int dy[100][100];

int c[100][100];

int zlo;

ii get(int x, int y, int p) {
	int nx = x + dx[x][y] * p;
	int ny = y + dy[x][y] * p;
	if (nx < 0) nx += n;
	if (nx >= n) nx -= n;
	if (ny < 0) ny += m;
	if (ny >= m) ny -= m;
	re mp(nx, ny);
}

int mod = 1000003;
int o;

vi v[10100];
queue<int> q;

int sum[10100];
int col[10100];
int color[10100];

int lol[10100];

void parse(int x) {
	if (col[x] == 0) {
		o = 0;
		re;
	}
	rep(i, sz(v[x])) {
		int u = v[x][i];
		col[u]--;
		if (lol[u] == 0 && col[u] <= 1) {
			lol[u] = 1;
			q.push(u);
		}
	}
}

void go(int x, int c) {
	color[x] = c;
	if (col[x] >= 2)
	sum[c]++;
	rep(i, sz(v[x])) {
		int u = v[x][i];
		if (color[u] == -1) {
			go(u, c);
		}
	}
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);

		cin >> n >> m;
		rep(i, n) {
			string s;
			cin >> s;
			rep(j, m) {
				dx[i][j] = 0;
				dy[i][j] = 0;
				if (s[j] == '-')
					dy[i][j] = 1;
				if (s[j] == '|')
					dx[i][j] = 1;
				if (s[j] == '\\') {
					dx[i][j] = 1;
					dy[i][j] = 1;
				}
				if (s[j] == '/') {
					dx[i][j] = 1;
					dy[i][j] = -1;
				}
			}
		}

		rep(i, n * m)
			v[i].clear();

		ll ans = 1;
		rep(i, n) rep(j, m) {
			ii tmp1, tmp2;
			tmp1 = get(i, j, -1);
			tmp2 = get(i, j, 1);
			int a = tmp1.fi * m + tmp1.se;
			int b = tmp2.fi * m + tmp2.se;

			v[a].pb(b);
			v[b].pb(a);
		}

		o = 1;
		fill(lol, 0);

		rep(i, m * n) {
			if (sz(v[i]) == 0) {
				o = 0;
				break;
			}
			if (sz(v[i]) == 1) {
				q.push(i);
				lol[i] = 1;
			}
			col[i] = sz(v[i]);
		}

		if (!o) {
			cout << 0 << endl;
			continue;
		}

		while (!q.empty()) {
			parse(q.front());
			q.pop();
		}
/*
		rep(i, n * m)
		if (col[i] >= 2)
		cout << i << ' ' << col[i] << ' ' << lol[i] << endl;*/


		if (!o) {
			cout << 0 << endl;
			continue;
		}

		fill(sum, 0);

		fill(color, -1);
		int cc = 0;
		rep(i, n * m) {
			if (col[i] > 0 && color[i] == -1) {
				go(i, cc++);
			}
		}

//		rep(i, cc)
//		cout << sum[i] << endl;

		rep(i, cc) {
			ans = (ans * 2) % mod;
		}

		cout << ans % mod << endl;
	}

	re 0;
}


#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 1000;

int n;
int m, k;
vi v[N];
vii u[N];
int was[N];
int q[N];
int preve[N];
int prev[N];
int d[2][N];
int cf[N * N];
int e;

int go (int t, int s) {
	memset (was, 0, sizeof (was));
	d[t][s] = 0;
	int l = 0, r = 1;
	q[0] = s;
	was[s] = 1;
	while (l < r) {
		int x = q[l++];
		for (int i = 0; i < sz (v[x]); i++) {
			int y = v[x][i];
			if (!was[y]) {
				was[y] = 1;
				d[t][y] = d[t][x] + 1;
				q[r++] = y;
			}
		}
	}
	re 0;
}

int addedge (int a, int b, int c) {
	cf[e] = c;
	u[a].pb (mp (b, e));
	e++;
	cf[e] = 0;
	u[b].pb (mp (a, e));
	e++;
	re 0;
}

int flow (int s, int t) {
	memset (was, 0, sizeof (was));
	int l = 0, r = 1;
	q[0] = s;
	while (l < r) {
		int x = q[l++];
		if (x == t) re 1;
		for (int i = 0; i < sz (u[x]); i++) {
			int y = u[x][i].fi;
			int z = u[x][i].se;
			if (cf[z] > 0 && !was[y]) {
				was[y] = 1;
				prev[y] = x;
				preve[y] = z;
				q[r++] = y;
			}
		}
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b);
			v[a].pb (b);
			v[b].pb (a);
		}
		go (0, 0);
		go (1, n - 1);
		for (int i = 0; i < 2 * n; i++) u[i].clear ();
		e = 0;
		for (int i = 0; i < n; i++) {
			addedge (2 * i, 2 * i + 1, 1);
			for (int j = 0; j < sz (v[i]); j++)
				if (d[0][i] + 1 + d[1][v[i][j]] == d[1][0])
					addedge (2 * i + 1, 2 * v[i][j], 1e9);
		}
		int ans = 0;
		if (d[1][0] == 1)
			ans = 1e9;
		else
		while (flow (1, 2 * n - 2)) {
			ans++;
			int j = 2 * n - 2;
			while (j != 1) {
				int k = prev[j];
				int z = preve[j];
				cf[z]--;
				cf[z ^ 1]++;
				j = k;
			}
		}
		cout << "Case #" << it << ": " << d[1][0] + 1 + int (ans <= k - 1) << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
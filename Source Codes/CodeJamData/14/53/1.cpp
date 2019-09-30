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

const int N = 2000;

int n;
int m;
vii v[N + 1];
int x[N + 1];
int y[N + 1];
int z[N + 1];
vii w[2];
vi u;
vii f;
vii dif[N + 1];
int use[N][N];

bool l1 (ii a, ii b) {
	re a.se < b.se || (a.se == b.se && a.fi < b.fi);
}

bool l2 (ii a, ii b) {
	re a.fi > b.fi || (a.fi == b.fi && a.se > b.se);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		for (int i = 1; i <= N; i++) v[i].clear ();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s >> x[i];
			y[i] = int (s == "E") - int (s == "L");
			z[i] = 0;
			if (x[i] > 0) v[x[i]].pb (mp (i, y[i]));
		}
		w[0].clear ();
		w[1].clear ();
		f.clear ();
		for (int i = 1; i <= N; i++)
			for (int j = 0; j + 1 < sz (v[i]); j++)
				if (v[i][j].se == v[i][j + 1].se)
					w[int (v[i][j].se == -1)].pb (mp (v[i][j].fi, v[i][j + 1].fi));
				else
				if (v[i][j].se == 1)	
					f.pb (mp (v[i][j].fi, v[i][j + 1].fi));
		int bad = 0;
		sort (all (w[0]), l1);
		for (int i = 0; i < sz (w[0]); i++) {
			int ok = 0;
			for (int j = w[0][i].fi; j <= w[0][i].se; j++)
				if (x[j] == 0 && y[j] == -1 && !z[j]) {
					f.pb (mp (w[0][i].fi, j));
					z[j] = 1;
					ok = 1;
					break;
				}
			if (!ok) bad = 1;
		}
		sort (all (w[1]), l2);
		for (int i = 0; i < sz (w[1]); i++) {
			int ok = 0;
			for (int j = w[1][i].se; j >= w[1][i].fi; j--)
				if (x[j] == 0 && y[j] == 1 && !z[j]) {
					f.pb (mp (j, w[1][i].se));
					z[j] = 1;
					ok = 1;
					break;
				}
			if (!ok) bad = 1;
		}
		int ans = 0;
		if (!bad) {
			u.clear ();
			for (int i = 1; i <= N; i++)
				if (!v[i].empty () && v[i][0].se == -1)
					u.pb (v[i][0].fi);
			sort (all (u));
			for (int i = 0; i < sz (u); i++)
				for (int j = u[i]; j >= 0; j--)
					if (x[j] == 0 && y[j] == 1 && !z[j]) {
						f.pb (mp (j, u[i]));
						z[j] = 1;
						break;
					}
			u.clear ();
			for (int i = 1; i <= N; i++)
				if (!v[i].empty () && v[i][sz (v[i]) - 1].se == 1)
					u.pb (v[i][sz (v[i]) - 1].fi);
			sort (all (u));
			reverse (all (u));
			int col = sz (u);
			for (int i = 0; i < sz (u); i++)
				for (int j = u[i]; j < n; j++)
					if (x[j] == 0 && y[j] == -1 && !z[j]) {
						f.pb (mp (u[i], j));
						z[j] = 1;
						col--;
						break;
					}
			for (int i = 0; i < n; i++) dif[i].clear ();
			for (int i = 0; i < n; i++)
				if (x[i] == 0 && y[i] == -1) {
					int u = -1;
					for (int j = 0; j < sz (f); j++)
						if (f[j].fi <= i)
							u = max (u, f[j].se);
					for (int j = i + 1; j <= u; j++)
						if (x[j] == 0 && y[j] == 1)
							dif[j - i].pb (mp (i, j));
				}
			memset (use, 0, sizeof (use));
			for (int i = 0; i < sz (f); i++)
				for (int j = f[i].fi + 1; j < f[i].se; j++)
					use[i][j] = 1;
			for (int i = n - 1; i > 0; i--)
				for (int j = 0; j < sz (dif[i]); j++) {
					int a = dif[i][j].fi;
					int b = dif[i][j].se;
					if (!z[a] && !z[b]) {
						for (int t = 0; t < sz (f); t++) {
							int ok = 1;
							for (int c = a; c <= b; c++)
								if (!use[t][c]) {
									ok = 0;
									break;
								}
							if (ok) {
								z[a] = z[b] = 1;
								for (int c = a; c <= b; c++)
									use[t][c] = 0;
								break;
							}
						}
//						printf ("%d %d\n", a, b);
//						z[a] = z[b] = 1;
					}	
				}
//			for (int i = 0; i < sz (f); i++) printf ("%d %d\n", f[i].fi, f[i].se);
//			printf ("%d\n", col);
//			for (int i = 0; i < n; i++)
//				if (x[i] == 0 && !z[i])
//					printf ("%d ", y[i]);
			int bal = 0, bot = 0;
			for (int i = 0; i < n; i++)
				if (x[i] == 0 && !z[i]) {
					bal += y[i];
					bot = min (bot, bal);
				}
			ans = col + (bal - bot);
		}
		cout << "Case #" << it << ": ";
		if (bad) cout << "CRIME TIME"; else cout << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
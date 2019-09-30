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

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

int n;
int m;

pair<ii, int> w[800];
int tp[210][210];
vector<pair<ii, int> > p;
pair<ii, int> prev[210][210][4];
int was[210][210][4];
pair<ii, int> q[210*210*4];
int ct;
vector<pair<int, ii> > v;

int out (pair<ii, int> x) {
	if (x.se == -1) re 0;
	out (prev[x.fi.fi][x.fi.se][x.se]);
//	printf ("%d %d %d\n", x.fi.fi, x.fi.se, x.se);
	p.pb (x);
	re 0;
}

int go (int s, int t) {
//	printf ("%d -> %d\n", s + 1, t + 1);
	ct++;
	int l = 0, r = 1;
	q[0] = w[s];
	was[w[s].fi.fi][w[s].fi.se][w[s].se] = ct;
	prev[w[s].fi.fi][w[s].fi.se][w[s].se] = mp (mp (0, 0), -1);
	while (l < r) {
		pair<ii, int> x = q[l++];
		if (x.fi == mp (w[t].fi.fi - di[w[t].se], w[t].fi.se - dj[w[t].se])) {
			p.clear ();
			out (x);
			for (int i = 0; i + 1 < sz (p); i++)
				tp[p[i].fi.fi][p[i].fi.se] = p[i].se ^ p[i + 1].se;
			re 1;
		}
		if (x.fi.fi <= 0 || x.fi.se <= 0 || x.fi.fi > n || x.fi.se > m) continue;
		for (int t = 0; t < 4; t++) {
			if (t == x.se || t == (x.se ^ 2)) continue;
			if (tp[x.fi.fi][x.fi.se] != -1 && tp[x.fi.fi][x.fi.se] != (t ^ x.se)) continue;
			pair<ii, int> y = mp (mp (x.fi.fi + di[t], x.fi.se + dj[t]), t);
			if (was[y.fi.fi][y.fi.se][y.se] == ct) continue;
			was[y.fi.fi][y.fi.se][y.se] = ct;
			prev[y.fi.fi][y.fi.se][y.se] = x;
			q[r++] = y;
		}
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
		v.clear ();
		for (int i = 0; i < n + m; i++) {
			int p, q;
			scanf ("%d%d", &p, &q); p--; q--;
			if (p > q) swap (p, q);
			v.pb (mp (min (q - p, 2 * (n + m) - (q - p)), mp (p, q)));
		}
		sort (all (v));
		memset (tp, -1, sizeof (tp));
		for (int i = 0; i < m; i++) w[i] = mp (mp (1, i + 1), 2);
		for (int i = 0; i < n; i++) w[i + m] = mp (mp (i + 1, m), 3);
		for (int i = 0; i < m; i++) w[i + m + n] = mp (mp (n, m - i), 0);
		for (int i = 0; i < n; i++) w[i + 2 * m + n] = mp (mp (n - i, 1), 1);
		int ok = 1;
		for (int i = 0; i < sz (v); i++)
			if (!go (v[i].se.fi, v[i].se.se)) {
				ok = 0;
				break;
			}
		cout << "Case #" << it << ":" << endl;
		if (!ok) printf ("IMPOSSIBLE\n"); else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++)
					if (tp[i][j] == 1)
						printf ("/");
					else
						printf ("\\");	
				printf ("\n");
			}
		}
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
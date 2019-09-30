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
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const ll INF = 1e18;
const int MAX = 1000;

int n;
int m;
ll x[1001], y[1001], z[1001];
ll ax, ay;
ll a[1001], b[1001];

ll xx[2][2], yy[2][2];

vector<ll> va, vb;
map<ll, int> wa, wb;

ll dist (ll a, ll b) { re abs (a) + abs (b); }

int d[2010][2010][4];

int add (int i1, int j1, int i2, int j2, int k) {
	d[i1][j1][k]++;
	d[i2][j1][k]--;
	d[i1][j2][k]--;
	d[i2][j2][k]++;
	re 0;
}

int upd (ll x, ll y) {
//	printf ("	%I64d %I64d\n", x, y);
	if (dist (x, y) < dist (ax, ay) || (dist (x, y) == dist (ax, ay) && mp (x, y) > mp (ax, ay))) {
		ax = x;
		ay = y;
	} 
	re 0;
}

int check2 (ll x, ll y, ll a1, ll a2, ll b1, ll b2, int v0, int v1, int h0, int h1) {
	for (int dx = -2; dx <= 2; dx++)
		for (int dy = -2; dy <= 2; dy++) {
			ll nx = x + dx;
			ll ny = y + dy;
//			printf ("	%I64d %I64d = %I64d %I64d\n", nx, ny, nx + ny, nx - ny);
			if (nx + ny >= a1 && nx + ny <= a2 && nx - ny >= b1 && nx - ny <= b2) {
				int ty = int (h0 == 0);
				int tx = int (v0 == 0);
				if (v0 + v1 == 0) {
					if ((ny & 1) == ty) upd (nx, ny);
				} else
				if (h0 + h1 == 0) {
					if ((nx & 1) == tx) upd (nx, ny);
				} else {
					if ((ny & 1) == ty && (nx & 1) == tx) upd (nx, ny);
				}
			}	
		}
	re 0;
}

int main () {
	double start = clock ();
	double last = clock ();
	int tt;
	cin >> tt;

	for (int it = 1; it <= tt; it++) {
			
		scanf ("%d", &n);
		va.clear ();
		vb.clear ();

		for (int i = 0; i < n; i++) {
			string s;
			cin >> x[i] >> y[i] >> s;
			a[i] = x[i] + y[i];
			b[i] = x[i] - y[i];
			z[i] = int (s == "#");
			va.pb (a[i]);
			vb.pb (b[i]);
		}	
		va.pb (0);
		vb.pb (0);
		va.pb (-INF);
		vb.pb (-INF);
		va.pb (INF);
		vb.pb (INF);

		sort (all (va));
		va.resize (unique (all (va)) - va.begin ());
		
		sort (all (vb));
		vb.resize (unique (all (vb)) - vb.begin ());

		wa.clear ();
		wb.clear ();

		int ra = 0;
		for (int i = 0; i < sz (va); i++) {
			if (i == 0 || va[i - 1] != va[i]) ra++;
			wa[va[i]] = ra - 1;
		}

		int rb = 0;
		for (int i = 0; i < sz (vb); i++) {
			if (i == 0 || vb[i - 1] != vb[i]) rb++;
			wb[vb[i]] = rb - 1;
		}

		memset (d, 0, sizeof (d));

		for (int i = 0; i < n; i++) {
			int ai = wa[a[i]];
			int bi = wb[b[i]];
			add (0, 0, ai, bi, z[i] ^ (x[i] & 1));
			add (ai, 0, ra - 1, bi, 2 + (z[i] ^ (y[i] & 1)));
			add (0, bi, ai, rb - 1, 2 + (z[i] ^ (y[i] & 1)));
			add (ai, bi, ra - 1, rb - 1, z[i] ^ (x[i] & 1));
		}

		ax = INF; ay = INF;

		for (int i = 0; i + 1 < ra; i++)
			for (int j = 0; j + 1 < rb; j++) {
				for (int k = 0; k < 4; k++) {
					if (i > 0) d[i][j][k] += d[i - 1][j][k];
					if (j > 0) d[i][j][k] += d[i][j - 1][k];
					if (i > 0 && j > 0) d[i][j][k] -= d[i - 1][j - 1][k];
				}
				int v0 = d[i][j][0], v1 = d[i][j][1];
				int h0 = d[i][j][2], h1 = d[i][j][3];
//				printf ("%d %d = %d %d %d %d : %I64d %I64d %I64d %I64d\n", i, j, v0, v1, h0, h1, va[i], vb[j], va[i + 1], vb[j + 1]);
				if (v0 != 0 && v1 != 0) continue;
				if (h0 != 0 && h1 != 0) continue;
				for (int t = 0; t < 2; t++)
					for (int s = 0; s < 2; s++) {
						ll x = (va[i + t] + vb[j + s]) / 2;
						ll y = (va[i + t] - vb[j + s]) / 2;
						check2 (x, y, va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
					}
				check2 (0, va[i], va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (0, va[i + 1], va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (0, -vb[j], va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (0, -vb[j + 1], va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (va[i], 0, va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (va[i + 1], 0, va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (vb[j], 0, va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
				check2 (vb[j + 1], 0, va[i], va[i + 1], vb[j], vb[j + 1], v0, v1, h0, h1);
			}

			
		cout << "Case #" << it << ": ";

		if (ax == INF) printf ("Too damaged"); else printf ("%I64d %I64d", ax, ay);

		cout << endl;
		double current = clock ();
		fprintf (stderr, "%d / %d = %.10f : %.10f\n", it, tt, (current - last) / CLOCKS_PER_SEC, (current - start) / CLOCKS_PER_SEC);
		last = current;
	}
	return 0;
}
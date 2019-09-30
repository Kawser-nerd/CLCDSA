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

const int MAX = 300000;

int n;
int m;

ii q[MAX];
ii nq[10 * MAX];
int x[10], y[10];
set<ii> all;

bool l1 (ii a, ii b) {
	re (ll)a.fi * a.fi + (ll)a.se * a.se > (ll)b.fi * b.fi + (ll)b.se * b.se;
}

ii rot (int x1, int y1, int x2, int y2) {
	re mp (x2 + (y1 - y2), y2 - (x1 - x2));
}

int main () {
	double start = clock ();
	double last = clock ();
	int tt;
	cin >> tt;

	for (int it = 1; it <= tt; it++) {
		
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);

		
		cout << "Case #" << it << ": ";

		int o = 1;

		q[0] = mp (0, 0);

		double ans = 0;

		int c0 = 0, c1 = 0, c2 = 0;
//		all.clear ();

		for (int i = 0; i < m; i++) {
			int no = 0;

			ll md = 0;
			if (o == MAX) md = (ll)q[o - 1].fi * q[o - 1].fi + (ll)q[o - 1].se * q[o - 1].se;
			for (int j = 0; j < o; j++)
				for (int k = 0; k < n; k++) {
					ii tmp = rot (q[j].fi, q[j].se, x[k], y[k]);
					if ((ll)tmp.fi * tmp.fi + (ll)tmp.se * tmp.se < md) { c0++; continue; }
//					if (all.find (tmp) != all.end ()) { c2++; continue; }
					nq[no++] = tmp;
				}
			sort (nq, nq + no, l1);
			int ono = no;
			no = unique (nq, nq + no) - nq;
			c1 += ono - no;
			o = min (no, MAX);
			for (int i = 0; i < o; i++) {
				q[i] = nq[i];
//				all.insert (q[i]);
			}	
			ans = max (ans, sqrt (sqr ((ll)q[0].fi) + sqr ((ll)q[0].se) + 0.0));
		}

		printf ("%.10f", ans);

		cout << endl;
		double current = clock ();
		fprintf (stderr, "%d / %d = %.10f : %.10f %d %d %d\n", it, tt, (current - last) / CLOCKS_PER_SEC, (current - start) / CLOCKS_PER_SEC, c0, c1, c2);
		last = current;
	}
	return 0;
}
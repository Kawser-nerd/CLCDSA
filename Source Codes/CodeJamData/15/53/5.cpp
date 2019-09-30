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

int n;
int m;
int y;
map<vi, ld> res[501];
set<vi> was[501];
set<pair<ld, pair<vi, int> > > all;
int p[501];
int s[501];

vi v;

int upd (vi v, int k, ld cur) {
	if (res[k].count (v) == 0 || res[k][v] > cur + 1e-7) {
//		printf ("%d %d %.10f\n", sz (v), k, cur);
		res[k][v] = cur;
		all.insert (mp (cur, mp (v, k)));
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &y, &n);		
		for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &s[i]);
			if (p[i] < 0) s[i] *= -1;
		}	
		p[n] = 0;
		s[n] = 0;
		v.clear ();
		for (int i = 0; i < n; i++) v.pb (i);
		all.clear ();
		for (int i = 0; i <= n; i++) {
			res[i].clear ();
			was[i].clear ();
		}
		res[n][v] = 0;
		all.insert (mp (0, mp (v, n)));
		ld ans = 0;
		int kkk = 0;
		while (!all.empty ()) {
			pair<ld, pair<vi, int> > x = *all.begin();
			all.erase (all.begin ());
			if (sz (x.se.fi) == 0) {
				ans = x.fi;
				break;
			}
			if (was[x.se.se].count (x.se.fi)) continue;
			was[x.se.se].insert (x.se.fi);
//			kkk++;
//			if (kkk % 10000 == 0) cerr << kkk << endl;
			pair<ld, int> b1 (1e18, -1), b2 (1e18, -1);
			ld cur = p[x.se.se] + s[x.se.se] * x.fi;
//			for (auto i : x.se.fi) printf ("%d ", i);
//			printf (" : %d = %.10f %.10f\n", x.se.se, x.fi, cur);
			for (int j = 0; j < sz (x.se.fi); j++) {
				int k = x.se.fi[j];
				ld now = p[k] + s[k] * x.fi;
//				printf ("%d = %.10f %d %d\n", k, now, p[k], s[k]);
				if (now > cur - 1e-6) b1 = min (b1, mp ((now - cur) / (y - abs (s[k])), k));
				if (now < cur + 1e-6) b2 = min (b2, mp ((cur - now) / (y - abs (s[k])), k));
			}
//			printf ("%.10f %d\n", b1.fi, b1.se);
//			printf ("%.10f %d\n", b2.fi, b2.se);
			if (b1.se != -1) {	
				vi w = x.se.fi;
				for (int j = 0; j < sz (w); j++)
					if (w[j] == b1.se) {
						w.erase (w.begin () + j);
						break;
					}
				upd (w, b1.se, x.fi + b1.fi);
			}
			if (b2.se != -1) {	
				vi w = x.se.fi;
				for (int j = 0; j < sz (w); j++)
					if (w[j] == b2.se) {
						w.erase (w.begin () + j);
						break;
					}
				upd (w, b2.se, x.fi + b2.fi);
			}
		}
		cout << "Case #" << it << ": ";
		printf ("%.10f", (D)ans);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
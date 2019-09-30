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

int n;
int m;
pair<ii, int> v[1000];
vector<pair<ii, int> > v1, v2, q;
int use[1000];
int p[1000];

ll vect (ii a, ii b, ii c) {
	re (ll)(b.fi - a.fi) * (c.se - b.se) - (ll)(c.fi - b.fi) * (b.se - a.se);
}

ll scal (ii a, ii b, ii c) {
	re (ll)(b.fi - a.fi) * (c.fi - b.fi) + (ll)(b.se - a.se) * (c.se - b.se);
}

int cross (ii a, ii b, ii c, ii d) {
	ll v1 = vect (a, c, b);
	ll v2 = vect (a, d, b);
	ll v3 = vect (c, a, d);
	ll v4 = vect (c, b, d);
	if (v1 * v2 < 0 && v3 * v4 <= 0 || v1 * v2 <= 0 && v3 * v4 < 0) re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d", &n);
                for (int i = 0; i < n; i++) {
                	scanf ("%d%d", &v[i].fi.fi, &v[i].fi.se);	
                	v[i].se = i;
                }	
                sort (v, v + n);
                for (int i = 0; i < n; i++) {
                	p[i] = v[i].se;
                	v[i].se = i;
                }	
                v1.clear ();
                v2.clear ();
                q.clear ();
                v1.pb (v[0]);
                v1.pb (v[1]);
                for (int i = 2; i < n; i++) {
                	while (sz (v1) > 1 && vect (v1[sz (v1) - 2].fi, v1[sz (v1) - 1].fi, v[i].fi) >= 0) v1.pop_back ();
                	v1.pb (v[i]);
                }
                v2.pb (v[0]);
                v2.pb (v[1]);
                for (int i = 2; i < n; i++) {
                	while (sz (v2) > 1 && vect (v2[sz (v2) - 2].fi, v2[sz (v2) - 1].fi, v[i].fi) <= 0) v2.pop_back ();
                	v2.pb (v[i]);
                }
                for (int i = 0; i < sz (v1); i++) q.pb (v1[i]);
                for (int i = sz (v2) - 2; i >= 0; i--) q.pb (v2[i]);
                memset (use, 0, sizeof (use));
                for (int i = 0; i < sz (q); i++) use[q[i].se] = 1;
                ll FULL = 0;
                for (int i = 0; i + 1 < sz (q); i++)
                	FULL += vect (q[i].fi, mp (0, 0), q[i + 1].fi);
		FULL = abs (FULL);
//		for (int i = 0; i < sz (q); i++) printf (" %d", p[q[i].se]);
//		printf ("\n");
                while (sz (q) < n + 1) {
                	ll ans = 1e15;
                	int ai, aj;
                	for (int i = 0; i < n; i++)
                		if (!use[i])
                			for (int j = 0; j + 1 < sz (q); j++) {
	                			ll cv = vect (q[j].fi, v[i].fi, q[j + 1].fi);
	                			ll sv = scal (q[j].fi, v[i].fi, q[j + 1].fi);
	                			int bad = 0;
						for (int a = 0; a + 1 < sz (q); a++) {
							if (cross (q[a].fi, q[a + 1].fi, q[j].fi, v[i].fi))
								bad = 1;
							if (cross (q[a].fi, q[a + 1].fi, q[j + 1].fi, v[i].fi))
								bad = 1;
						}
//	                			printf ("%I64d %I64d\n", cv, sv);
	                			if (bad || cv < 0 || cv == 0 && sv <= 0) continue;
	                			if (cv < ans) {
	                				ans = cv;
	                				ai = i;
	                				aj = j;
	                			}
	                		}
//	                printf ("%d %d %d\n", ai, aj, v[ai].se);
	        	use[ai] = 1;
	        	q.pb (v[ai]);
	        	for (int t = sz (q) - 1; t > aj + 1; t--) q[t] = q[t - 1];
	        	q[aj + 1] = v[ai];
//		for (int i = 0; i < sz (q); i++) printf (" %d", p[q[i].se]);
//		printf ("\n");
//			for (int i = 0; i < sz (q); i++) printf (" %d", q[i].se);
//			printf ("\n");
                }
                ll NOW = 0;
                for (int i = 0; i + 1 < sz (q); i++)
                	NOW += vect (q[i].fi, mp (0, 0), q[i + 1].fi);
		NOW = abs (NOW);
		if (2 * NOW <= FULL) cerr << "bad" << endl;

		cout << "Case #" << it << ":";

		for (int i = 0; i + 1 < sz (q); i++) printf (" %d", p[q[i].se]);

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << " " << NOW << " " << FULL << endl;
		int bad = 0;
		for (int i = 0; i + 2 < sz (q); i++)
			for (int j = i + 1; j + 1 < sz (q); j++)
				if (cross (q[i].fi, q[i + 1].fi, q[j].fi, q[j + 1].fi))
					bad = 1;
		if (bad) cerr << "bad" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
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
template<class T> T sqr(T x) { re x * x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
vector<pair<ld, ii> > v;
int was[300*300];
int g[300*300];
set<ii> now;
                
#ifdef PARALLEL
int main (int argv, char **argc) {
	if (argv < 4) {
		printf ("wrong command line\n");
		re 0;
	}
	int PART = stoi (argc[1]);
	int NUM = stoi (argc[2]);
	freopen (argc[3], "r", stdin);
	freopen (argc[4], "w", stdout);
#else
int main () {
#endif
	int tt;
	cin >> tt;
#ifdef PARALLEL
	int CNT = (tt + NUM - 1) / NUM;
#endif	
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
#ifdef PARALLEL
		if ((it - 1) >= PART * CNT && (it - 1) < (PART + 1) * CNT) {
#endif
			v.clear ();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i != 0 || j != 0) {
						ld ang = atan2l (j - 0.0, i - 0.0);
						ll dd = sqr ((ll)i) + sqr ((ll)j);
						ld d = sqrt ((ld)dd);
						ld dif = asinl ((ld)m / 1000000.0 / d);
						g[i * n + j] = dd;
						was[i * n + j] = 0;
						v.pb (mp (ang - dif, mp (i * n + j, 0)));
						v.pb (mp (ang + dif, mp (i * n + j, 1)));
					}
			sort (all (v));	
			now.clear ();
			for (int i = 0; i < sz (v); ) {
				int j = i;
				while (j < sz (v) && v[j].fi - v[i].fi < 1e-12) {
					int k = v[j].se.fi;
					if (v[j].se.se == 0) now.insert (mp (g[k], k)); else now.erase (mp (g[k], k));
					j++;
				}
				if (!now.empty ()) was[now.begin ()->se] = 1;
				i = j;
			}
			int ans = 0;
			for (int i = 0; i < n * n; i++) ans += was[i];
			cout << "Case #" << it << ": " << ans;
			cout << endl;
#ifdef PARALLEL
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it - PART * CNT, CNT, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / (it - PART * CNT) * CNT) / CLOCKS_PER_SEC);
		}	
#else
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
#endif
	}
	return 0;
}
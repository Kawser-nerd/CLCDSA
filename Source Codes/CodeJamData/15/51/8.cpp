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
int d;

int s0, as, cs, rs;
int m0, am, cm, rm;
int s[1000000];
int m[1000000];
int p[1000000];
int l[1000000];
int r[1000000];
vii v;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &d);		
		scanf ("%d%d%d%d", &s0, &as, &cs, &rs);
		scanf ("%d%d%d%d", &m0, &am, &cm, &rm);
		s[0] = s0;
		m[0] = m0;
		for (int i = 1; i < n; i++) {
			s[i] = ((ll)s[i - 1] * as + cs) % rs;
			m[i] = ((ll)m[i - 1] * am + cm) % rm;
			p[i] = m[i] % i;
		}
		for (int i = 0; i < n; i++) l[i] = r[i] = s[i];
		for (int i = 1; i < n; i++) {
			l[i] = min (l[i], l[p[i]]);
			r[i] = max (r[i], r[p[i]]);
		}
		v.clear ();
		for (int i = 0; i < n; i++)
			if (r[i] - l[i] <= d) {
				v.pb (mp (r[i] - d, -1));
				v.pb (mp (l[i], 1));
			}
		sort (all (v));
		int cur = 0, ans = 0;
		for (int i = 0; i < sz (v); i++) {
			cur -= v[i].se;
			ans = max (ans, cur);
		}
		cout << "Case #" << it << ": " << ans;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
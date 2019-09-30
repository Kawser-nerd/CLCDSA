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

int c;
ll l, n;
ll x[2000], y[2000], t[2000];

int cross (ll t1, ll x1, ll y1, ll t2, ll x2, ll y2) {
	ll l = max (t1, t2);
	ll r = min (t1 + abs (y1 - x1), t2 + abs (y2 - x2));
	if (l > r) re 0;
	ll ax = x1 - (l - t1);
	ll ay = x1 - (r - t1);
	ll bx = x2 + l - t2;
	ll by = x2 + r - t2;
//	printf ("%I64d %I64d %I64d %I64d\n", ax, ay, bx, by);
	if (ax % n == bx % n || ay % n == by % n || (ax > bx && ay < by)) re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%I64d%I64d", &c, &l, &n);
		int nc = c;
		for (int i = 0; i < c; i++) {
			scanf ("%I64d%I64d%I64d", &x[i], &y[i], &t[i]);
			x[i]--;
			y[i]--;
			if (y[i] < x[i]) {
				x[nc] = 0;
				y[nc] = y[i];
				t[nc] = t[i] + n - x[i];
				nc++;
				y[i] = n;
			}
		}
		c = nc;
//		for (int i = 0; i < c; i++) printf ("%I64d %I64d %I64d\n", t[i], x[i], y[i]);
		ll ans = 0;
		for (int nt = 0; nt <= l; nt++)
			for (int nx = 0; nx < n; nx++) {
				int cx = nx;
				for (int i = 0; nt + i + 1 <= l; i++) {
					if (cx == 0) cx = n;
					int cy = cx - 1;
					int ok = 1;
					for (int j = 0; j < c; j++)
						if (cross (i + nt, cx, cy, t[j], x[j], y[j]))
							ok = 0;
					if (!ok) break;
//					printf ("%d %d %d\n", i, cx, cy);
					ans = max (ans, (ll)i + 1);
					cx = cy;
				}
			}
		cout << "Case #" << it << ": " << ans;
		                               
		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}
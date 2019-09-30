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
typedef pair<ll, ll> pll;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 500000;

int n;
ll y[N + 1];
ll sum[N + 1];
pair<ll, int> v[N + 1];
string p, s;
int P;

int get (string p) {
	int x = 0;
	for (int i = 0; i < sz (p); i++)
		if (p[i] != '.')
			x = x * 10 + p[i] - '0';
	re x;
}

bool ls (pll a, pll b) {
	re a.fi * b.se < a.se * b.fi;
}

bool eq (pll a, pll b) {
	re a.fi * b.se == a.se * b.fi;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> p >> s;
		P = get (p);
		sum[0] = 0;
		for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i] - '0';
		for (int i = 0; i <= n; i++) v[i] = mp ((ll)1000000 * sum[i] - (ll)P * i, i);
		sort (v, v + n + 1);
		pair<pll, int> best (mp (2, 1), n);
		for (int i = 0; i < n; i++) {
			int a = v[i].se;
			int b = v[i + 1].se;
			if (a > b) swap (a, b);
			pll cur (abs ((ll)(sum[b] - sum[a]) * 1000000 - (ll)P * (b - a)), b - a);
			if (best.se == n || ls (cur, best.fi) || (eq (cur, best.fi) && a < best.se)) best = mp (cur, a);
		}
		cout << "Case #" << it << ": " << best.se << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
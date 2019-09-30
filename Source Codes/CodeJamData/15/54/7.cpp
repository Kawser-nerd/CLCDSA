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
typedef vector<pll> vll;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
ll e[40000];
ll f[40000];
vector<ll> w;
vll v;

ll res[100];

int check (vll& v, ll x) {
	int ok = 0;
	for (int i = 0; i < sz (v); i++)
		if (v[i].fi == x)
			ok = 1;
	if (!ok) re 0;
	if (x == 0) {
		for (int i = 0; i < sz (v); i++) {
			if (v[i].se % 2 != 0)
				re 0;	
			v[i].se /= 2;
		}
		re 1;
	}
	if (x < 0) {
		for (int i = sz (v) - 1, j = sz (v) - 1; i >= 0; i--)
			if (v[i].se != 0) {
				while (j >= 0 && v[j].fi > v[i].fi + x) j--;
				if (j < 0 || v[j].fi < v[i].fi + x || v[j].se < v[i].se)
					re 0;
				v[j].se -= v[i].se;	
			}
		re 1;
	}
	if (x > 0) {
		for (int i = 0, j = 0; i < sz (v); i++)
			if (v[i].se != 0) {
				while (j < sz (v) && v[j].fi < v[i].fi + x) j++;
				if (j == sz (v) || v[j].fi > v[i].fi + x || v[j].se < v[i].se)
					re 0;
//				printf ("%I64d %I64d %d %I64d\n", v[i].fi, v[i].se, j, v[j].se);
				v[j].se -= v[i].se;	
			}
		re 1;
	}
	re 0;
}

int go (int i, vll vv) {
	vll v;
	for (int j = 0; j < sz (vv); j++)
		if (vv[j].se != 0)
			v.pb (vv[j]);
//	for (auto x : v) cout << x.fi << "," << x.se << " ";
//	cout << endl;
	if (sz (v) == 1 && v[0].se == 1) {
		if (v[0].fi == 0) {
			for (int j = 0; j < i; j++)
				cout << res[j] << " ";
			re 1;
		}
		re 0;
	}
	for (int j = 0; j < sz (w); j++) {
		vv = v;
		if (check (vv, w[j])) {
			res[i] = w[j];
			if (go (i + 1, vv)) re 1;
		}
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> e[i];
		for (int i = 0; i < n; i++) cin >> f[i];
		v.clear ();
		for (int i = 0; i < n; i++) v.pb (mp (e[i], f[i]));
		w.clear ();
		for (int i = 0; i < n; i++) {
			vll vv = v;
			if (check (vv, e[i]))
				w.pb (e[i]);
		}
		cout << "Case #" << it << ": ";
		go (0, v);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
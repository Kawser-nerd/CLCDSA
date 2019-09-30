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

const int mod = 1000002013;

int n;
int m;
vector<pair<int, ii> > v;
ii q[2000];

int get (int a, int b) {
	int k = b - a;
	re ((ll)n * (n + 1) / 2 - (ll)(n - k) * (n - k + 1) / 2) % mod;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {


		scanf ("%d%d", &n, &m);
		int sum = 0;
		v.clear ();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf ("%d%d%d", &a, &b, &c);
			sum = (sum + (ll)get (a, b) * c) % mod;
			v.pb (mp (a, mp (0, c)));
			v.pb (mp (b, mp (1, c)));
		}
		sort (all (v));
		int ans = 0, r = 0;
		for (int i = 0; i < sz (v); i++)
			if (v[i].se.fi == 0)
				q[r++] = mp (v[i].fi, v[i].se.se);
			else {
				int cur = v[i].se.se;
				while (cur > 0) {
					int tmp = min (cur, q[r - 1].se);
					ans = (ans + (ll)get (q[r - 1].fi, v[i].fi) * tmp) % mod;
					cur -= tmp;
					q[r - 1].se -= tmp;
					if (q[r - 1].se == 0) r--;
				}
			}
		
		cout << "Case #" << it << ": " << (sum - ans + mod) % mod;

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}
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

ll n, m, k;

ll best (ll x) {
	ll y = k - x - 1, ans = 0;
	for (int i = 0; i < n; i++)
		if (y > 0) {
			ans = ans * 2;
			y = (y - 1) / 2;
		} else	ans = ans * 2 + 1;
	re ans;
}

ll worst (ll x) {
	ll y = x, ans = 0;
	for (int i = 0; i < n; i++)
		if (y > 0) {
			ans = ans * 2 + 1;
			y = (y - 1) / 2;
		} else ans = ans * 2;	
	re ans;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

	       	cin >> n >> m;
	       	k = (ll)1 << n;
	       	ll l, r, x, y;
	       	l = 0; r = (ll)1 << n;
	       	while (r - l > 1) {
	       		ll s = (l + r) / 2;
	       		if (worst (s) < m) l = s; else r = s;
	       	}
	       	x = l;
	       	l = 0; r = (ll)1 << n;
	       	while (r - l > 1) {
	       		ll s = (l + r) / 2;
	       		if (best (s) < m) l = s; else r = s;
	       	}
	       	y = l;
		
		cout << "Case #" << it << ": " << x << " " << y;

		cout << endl;

		cerr << it << " / " << tt << endl;
	}
	return 0;
}
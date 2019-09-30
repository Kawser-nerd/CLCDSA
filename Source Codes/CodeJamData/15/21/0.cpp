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
#include <cassert>

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

ll n;
int m;

ll rev (ll x) {
	ll y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	re y;
}

ll get (ll x) {
	ll base = 1;
	while (base * base <= x) base *= 10;
	ll ans = 0;
	while (x >= 10) {
		while ((base / 10) * (base / 10) > x) base /= 10;
		ll y = x % base;
		if (y == 0) {
			ans++;
			x--;
		} else {
			ans += y;
			x -= y - 1;
			ll z = rev (x);
			if (x != z) x = z; else x--;
		}
	}
	re ans + x;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		cout << "Case #" << it << ": " << get (n);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
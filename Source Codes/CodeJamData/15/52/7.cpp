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
int l[100];
int r[100];
int s[1000];
int x[1000];

int can (ll h) {
	for (int k = 0; k < m; k++)
		if (r[k] - l[k] > h)
			re 0;
	ll i = 0;
	ll j = i + h;
	ll a = 0, b = 0;
	for (int k = 0; k < m; k++) {
		ll ca = i - l[k];
		ll cb = j - r[k];
		a += ca;
		b += cb;
	}
	a -= s[0];
	b -= s[0];
	ll t1 = -a / m;
	while (a + t1 * m > 0) t1--;
	while (a + (t1 + 1) * m <= 0) t1--;
	ll t2 = -b / m;
	while (b + t2 * m < 0) t2++;
	while (b + (t2 - 1) * m >= 0) t2--;
	re int (t1 >= t2);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n - m + 1; i++) scanf ("%d", &s[i]);
		for (int i = 0; i < m; i++) {
			l[i] = r[i] = 0;
			x[i] = 0;
		}	
		for (int i = m; i < n; i++) {
			x[i] = x[i - m] + s[i - m + 1] - s[i - m];
			l[i % m] = min (l[i % m], x[i]);
			r[i % m] = max (r[i % m], x[i]);
//			if (it == 65) {
//				printf ("%d %d %d %d\n", s[i - m], l[i % m], r[i % m], x[i]);
//			}
		}
		ll l = -1, r = 1e10;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (can (s)) r = s; else l = s;
		}
		cout << "Case #" << it << ": " << r;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
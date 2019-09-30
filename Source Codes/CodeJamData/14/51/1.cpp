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
int x[1000000];
int p, q, r, s;

int can (ll h) {
	int pos = 0;
	for (int t = 0; t < 3; t++) {
		ll cur = 0;
		while (pos < n && cur + x[pos] <= h) {
			cur += x[pos];
			pos++;
		}
	}
	re int (pos == n);
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d%d%d", &n, &p, &q, &r, &s);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			x[i] = ((ll)i * p + q) % r + s;
			sum += x[i];
		}	
		ll l = -1, r = sum;
		while (r - l > 1) {
			ll s = (l + r) / 2;
			if (can (s)) r = s; else l = s;
		}
		cout << "Case #" << it << ": ";
		printf ("%.10f", 1 - (r + 0.0) / sum);
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}
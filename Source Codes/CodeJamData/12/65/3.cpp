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

int n;
int m;

int was[1 << 10][10];

int x[10], y[10];

int main () {
	double start = clock ();
	double last = clock ();
	int tt;
	cin >> tt;

	for (int it = 1; it <= tt; it++) {
		
		scanf ("%d", &n);
		for (int i = 0; i + 1 < n; i++) scanf ("%d%d", &x[i], &y[i]);

		int cur = 0, pos = 0;
		ll ans = 0;

		memset (was, 0, sizeof (was));

		while (pos != n - 1) {
			ans++;
			if (was[cur][pos]) { ans = -1; break; }
			was[cur][pos] = 1;
			cur ^= (1 << pos);
			if ((cur >> pos) & 1) pos = x[pos] - 1; else pos = y[pos] - 1;
		}
		
		cout << "Case #" << it << ": ";

		if (ans == -1) printf ("Infinity"); else printf ("%I64d", ans);



		cout << endl;
		double current = clock ();
		fprintf (stderr, "%d / %d = %.10f : %.10f\n", it, tt, (current - last) / CLOCKS_PER_SEC, (current - start) / CLOCKS_PER_SEC);
		last = current;
	}
	return 0;
}
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

double x[50000];

int can (double h) {
	for (int i = 0; i < n; i++) {
		double l = -1e18, r = 1e18;
		for (int j = 0; j < n; j++)
			if (i != j) {
				double a = (x[j] - x[i]) / (j - i);
				double b = (x[j] - x[i] + 2 * h) / (j - i);
				if (j < i) swap (a, b);
				l = max (l, a);
				r = min (r, b);
			}
		if (l <= r) re 1;
	}
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%lf", &x[i]);
		double l = 0, r = 1e6;
		for (int it1 = 0; it1 < 50; it1++) {
			double s = (l + r) / 2;
			if (can (s)) r = s; else l = s;
		}
		cout << "Case #" << it << ": ";

		printf ("%.10f", (l + r) / 2);

		cout << endl;

		cerr << it << " / " << tt << " " << clock () << endl;
	}
	return 0;
}
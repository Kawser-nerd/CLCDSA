#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;

template<class T> T abs(T x) {
	return x > 0 ? x : -x;
}

int m;
int n;

double val[500];
double sum;

int check(double c, int p) {
	double cur = val[p] + sum * c;

	double x = c;
	rep(i, n) {
		if (i == p)
			continue;
		double tmp = cur - val[i];
		if (tmp > 0)
			x += tmp / sum;
	}
	if (x > 1)
		re 1;
	re 0;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> n;
		rep(i, n)
		cin >> val[i];

		sum = accumulate(val, val + n, 0.0);

		rep(i, n) {
			double l = 0, r = 1;
			rep(o, 50) {
				double c = (l + r) / 2;
				if (check(c, i))
					r = c;
				else
					l = c;
			}
			printf("%.10lf ", (l + r) * 50);
		}
		cout << endl;
	}

	re 0;
}

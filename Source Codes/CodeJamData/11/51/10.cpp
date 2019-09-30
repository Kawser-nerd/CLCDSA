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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;
int c[2];
int x[2][1000], y[2][1000];

double get(int p, double xx) {
	double ans = 0;
	for (int i = 1; i < c[p]; i++) {
		if (x[p][i] < xx) {
			ans += (x[p][i] - x[p][i - 1]) * .5 * (y[p][i] + y[p][i - 1]);
		}
		else {
			double yy = ((xx - x[p][i - 1]) * y[p][i] + (x[p][i] - xx) * y[p][i - 1]) / (x[p][i] - x[p][i - 1]);
			ans += (xx - x[p][i - 1]) * .5 * (yy + y[p][i - 1]);
			break;
		}
	}
	re ans;
}

double get(double x) {
	re abs(get(1, x) - get(0, x));
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d:", tt + 1);

		double w;
		int g;
		cin >> w >> c[0] >> c[1] >> g;
		rep(i, c[0])
		cin >> x[0][i] >> y[0][i];
		rep(i, c[1])
		cin >> x[1][i] >> y[1][i];
		cout << endl;

		double sum = get(w);
		sum /= g;
		rep(i, g - 1) {
			double l = 0, r = w;
			rep(tt, 50) {
				double c = (l + r) / 2;
				if (get(c) > (i + 1) * sum) {
					r = c;
				}
				else
					l = c;
			}
			printf("%.6lf\n", (l + r) / 2);
		}
	}

	re 0;
}


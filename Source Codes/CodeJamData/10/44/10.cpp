#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <deque>
#include <map>
#include <stack>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))
#define sqr(x) ((x)*(x))
#define For(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) For(i,0,n)
#define rrep(i,n) for (int i = ((n) - 1); i >= 0; i--)
#define re return
#define fi first
#define se second
#define y0 y47847892
#define y1 y47824262
#define fill(x, val) memset(x, val, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

#pragma comment(linker, "/STACK:16777216")

template<class T> T abs(T x) { return x > 0 ? x : -x;}

int n;
int m;

double pi = 2 * acos(0.0);

double dist(double x1, double y1, double x2, double y2) {
	re sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

double geta(double a, double b, double c) {
	re acos((sqr(c) - sqr(a) - sqr(b)) / (-2 * a * b));
}

double getans(double r1, double r2, double d) {
	double ans = 0;
	double a1 = geta(r1, d, r2);
	ans += a1 * sqr(r1) - .5 * sqr(r1) * sin(2 * a1);
	double a2 = geta(r2, d, r1);
	ans += a2 * sqr(r2) - .5 * sqr(r2) * sin(2 * a2);
	re ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int tc;
	cin >> tc;

	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		double x1, y1, x2, y2, xc, yc;
		cin >> n >> m;
		cin >> x1 >> y1 >> x2 >> y2;

		rep(i, m) {
			cin >> xc >> yc;
			double r1 = dist(x1, y1, xc, yc);
			double r2 = dist(x2, y2, xc, yc);
			double d = dist(x1, y1, x2, y2);
			printf("%.6lf ", getans(r1, r2, d));
		}
		cout << endl;
	}

	return 0;
}

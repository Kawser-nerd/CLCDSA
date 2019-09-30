#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const double eps = 1E-7;

int m, v;

double d[57][57][57];
//bool u[57][57][57];

double get(int n, int x, int y) {
	if (n >= v) return 1.0;
	if (n <= 0) return 0.0;
	//if (y > m) return 0.0;
	return d[n][x][y];
}

double relax(int n, int x, int y) {
	double opt1 = 0.0;
	int nn = n - (2 * y - x);
	for (int i = 1; i <= min(nn, m); ++i)
		opt1 = max(opt1, get(nn, i, i));

	double opt2 = 0.0;
	if (y * 2 <= m)
		opt2 = get(n, x, 2 * y);

	double res = 0.0;
	nn = n + x;
	for (int i = 1; i <= min(nn, m); ++i)
		res = max(res, get(nn, i, i));

	return 0.5 * max(opt1, opt2) + 0.5 * res;
}

void solve(int testNum) {
	printf("Case #%d: ", testNum + 1);
	int a;
	cin >> a >> m >> v;
	memset(d, 0, sizeof(d));
	for (int it = 0; it < 10000; ++it) {
		for (int i = 1; i < v; ++i)
			for (int j = 1; j <= min(m, i); ++j)
				for (int k = j; k <= m; k *= 2)
					d[i][j][k] = relax(i, j, k);
	}
	int fb = 1;
	double res = d[a][1][1];
	for (int i = 1; i <= min(a, m); ++i) {
		double cur = d[a][i][i];
		if (cur > (1 - eps) * res)
			res = cur, fb = i;
	}
	printf("%.10lf %d\n", res, fb);
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		solve(it);
	}
	return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// BEGIN CUT HERE
#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define sz size()

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
// END CUT HERE

const double EPS = 1e-9;

/* Geometry */
struct Point
{
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
	void read() {
		cin >> x >> y;
	}
};

Point operator+(const Point &A, const Point &B) { return Point(A.x+B.x, A.y+B.y); }
Point operator-(const Point &A, const Point &B) { return Point(A.x-B.x, A.y-B.y); }
Point operator*(const Point &A, const double &B) { return Point(A.x*B, A.y*B); }
double operator^(const Point &A, const Point &B) { return A.x*B.y - A.y*B.x; }

double len(const Point &A) { return sqrt(A.x*A.x + A.y*A.y); }
double len(const Point &A, const Point &B) { return len(A-B); }

void solve()
{
	Point pv[3], qv[3];
	REP(i, 3)
		pv[i].read();
	REP(i, 3)
		qv[i].read();

	int i0 = 0, i1 = 1, i2 = 2;
	REP(j0, 3) REP(j1, 3) REP(j2, 3) {
		if ((j0 == j1) || (j0 == j2) || (j1 == j2))
			continue;

		Point p[3], q[3];
		p[0] = pv[i0];
		p[1] = pv[i1];
		p[2] = pv[i2];
		q[0] = qv[j0];
		q[1] = qv[j1];
		q[2] = qv[j2];

		// Test alike
		double ddd[] = { len(p[0], p[1])/len(q[0], q[1]),
			             len(p[1], p[2])/len(q[1], q[2]),
						 len(p[2], p[0])/len(q[2], q[0]) };
		bool good = (fabs(ddd[0]-ddd[1]) <= EPS) && (fabs(ddd[0]-ddd[2]) <= EPS);
		if (!good)
			continue;

		Point a = p[1] - p[0], b = p[2] - p[0];
		Point c = q[1] - q[0], d = q[2] - q[0];

		Point ti = a-c, tj = b-d, tk = q[0] - p[0];
		double d0 = ti ^ tj;
		double di = tk ^ tj;
		double dj = ti ^ tk;

		double i = di/d0, j = dj/d0;
		if ((i < 0) || (i > 1) || (j < 0) || (j > 1))
			continue;
		Point RES = p[0] + a*i + b*j;
		printf("%.6lf %.6lf\n", RES.x, RES.y);
		return;
	}
}

int main()
{
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++) {
		printf("Case #%d: ", iTest);
		solve();
	}
	return 0;
}

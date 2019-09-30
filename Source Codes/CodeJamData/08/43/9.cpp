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

const int MaxN = 1024;

struct Point {
	double x, y, z;

	Point() : x(0), y(0), z(z) {}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
};

Point operator + (const Point &a, const Point &b) { return Point(a.x+b.x, a.y+b.y, a.z+b.z); }
Point operator - (const Point &a, const Point &b) { return Point(a.x-b.x, a.y-b.y, a.z-b.z); }

struct Ship {
	Point loc;
	int p;
};

int N;
Ship ships[MaxN];
Point LLL, RRR;

double l1_dist(const Point &p)
{
	return abs(p.x) + abs(p.y) + abs(p.z);
}

double needEnergy(const Point &pnt)
{
	double need = 0.0;
	REP(i, N)
		need = max(need, l1_dist(ships[i].loc-pnt)/ships[i].p);
	return need;
}

bool madeMin;

void makeMin(double &res, Point &p, const Point &newPoint) {
	double newD = needEnergy(newPoint);
	if (newD < res) {
		madeMin = true;
		res = newD;
		p = newPoint;
	}
}

double minimize(Point pnt)
{
	double res = needEnergy(pnt), d = 0.5;
	Point D = RRR - LLL;
	while (d > 1e-10) {
		madeMin = false;
		makeMin(res, pnt, pnt + Point(d*D.x, 0, 0));
		makeMin(res, pnt, pnt - Point(d*D.x, 0, 0));
		makeMin(res, pnt, pnt + Point(0, d*D.y, 0));
		makeMin(res, pnt, pnt - Point(0, d*D.y, 0));
		makeMin(res, pnt, pnt + Point(0, 0, d*D.z));
		makeMin(res, pnt, pnt - Point(0, 0, d*D.z));
		if (!madeMin)
			d /= 2;
	}
	return res;
}

double rnd() { return double(rand()) / RAND_MAX; }

void solve(int iTest)
{
	scanf("%d", &N);
	REP(i, N)
		scanf("%lf %lf %lf %d", &ships[i].loc.x, &ships[i].loc.y, &ships[i].loc.z, &ships[i].p);

	LLL = ships[0].loc, RRR = ships[0].loc;
	REP(i, N) {
		LLL.x = min(LLL.x, ships[i].loc.x);
		LLL.y = min(LLL.y, ships[i].loc.y);
		LLL.z = min(LLL.z, ships[i].loc.z);
		RRR.x = max(RRR.x, ships[i].loc.x);
		RRR.y = max(RRR.y, ships[i].loc.y);
		RRR.z = max(RRR.z, ships[i].loc.z);
	}

	double best = 1e+10;
	REP(iter, 5000) {
		Point start = LLL;
		start.x += (RRR.x - LLL.x)*rnd();
		start.y += (RRR.y - LLL.y)*rnd();
		start.z += (RRR.z - LLL.z)*rnd();
		best = min(best, minimize(start));
	}

	printf("Case #%d: %.6lf\n", iTest, best);
}

int main()
{
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++)
		solve(iTest);
	return 0;
}

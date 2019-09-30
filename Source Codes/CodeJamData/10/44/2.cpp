#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <algorithm>

typedef double real;
static const real MINEPS = 1e-9;
static const real MAXEPS = 1e-7;
const real PI = 2.0 * acos(0.0);

//For good thresholding
inline bool EpsLess(real a, real b) {
	bool minr = (a < b - MINEPS);
	bool maxr = (a < b - MAXEPS);
	assert(minr == maxr);
	return minr;
}
inline bool EpsGreater(real a, real b) { return EpsLess(b, a); }
inline bool EpsLessEq(real a, real b) { return !EpsGreater(a, b); }
inline bool EpsGreaterEq(real a, real b) { return !EpsLess(a, b); }
inline bool EpsEqual(real a, real b) { return EpsLessEq(a, b) && EpsGreaterEq(a, b); }
inline bool EpsNotEqual(real a, real b) { return !EpsEqual(a, b); }

inline real sqr(real a) { return a*a; }

struct Point {
	real x, y;
	inline Point() {}
	inline Point(real _x, real _y) : x(_x), y(_y) {}

	inline real operator! () const {
		return sqrt(x*x + y*y);
	}
	inline real operator~ () const {
		double q = atan2(y, x);
		if (EpsLess(q, 0)) q += 2*PI;
		return q;
	}
	inline bool operator< (const Point &b) const {
		if (EpsNotEqual(x, b.x)) return x < b.x;
		if (EpsNotEqual(y, b.y)) return y < b.y;
		return false;
	}
	inline bool operator== (const Point &b) const {
		return EpsEqual(x, b.x) && EpsEqual(y, b.y);
	}

	inline Point operator- (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	inline Point operator+ (const Point &b) const {
		return Point(x+b.x, y+b.y);
	}
	inline Point operator* (real b) const {
		return Point(x*b, y*b);
	}
	inline Point operator/ (real b) const {
		return Point(x/b, y/b);
	}
};

inline real scal(const Point &a, const Point &b) {
	return a.x*b.x + a.y*b.y;
}
inline real vect(const Point &a, const Point &b) {
	return a.x*b.y - a.y*b.x;
}

std::vector<Point> ans;

void CrossLineCircle(const Point &la, const Point &lb, bool ea, bool eb, const Point &cc, real cr) {
	Point st = la - cc;
	Point dir = lb - la;

	real qa = scal(dir, dir);
	real qb = 2.0 * scal(st, dir);
	real qc = scal(st, st) - cr*cr;
	real qd = qb*qb - 4.0*qa*qc;
	if (EpsLess(qd, 0.0)) return;
	if (qd < 0.0) qd = 0.0;
	qd = sqrt(qd);

	real x1 = (-qb - qd) / (2.0 * qa);
	real x2 = (-qb + qd) / (2.0 * qa);

	if (!(ea && EpsLess(x1, 0.0) || eb && EpsGreater(x1, 1.0))) ans.push_back(la + dir*x1);
	if (!(ea && EpsLess(x2, 0.0) || eb && EpsGreater(x2, 1.0))) ans.push_back(la + dir*x2);
}

void CrossCircleCircle(const Point &c1, real r1, const Point &c2, real r2) {
	real d = !(c1-c2);
	if (EpsGreater(d, r1 + r2) || EpsLess(d, std::max(r1, r2) - std::min(r1, r2))) return;
	real la = 2.0 * (c2.x - c1.x);
	real lb = 2.0 * (c2.y - c1.y);
	real lc = sqr(c1.x)-sqr(c2.x) + sqr(c1.y)-sqr(c2.y) + sqr(r2)-sqr(r1);

	if (EpsEqual(la*la + lb*lb, 0.0)) return;

	Point a, b;
	static const real SETLEN = 1.0;
	if (fabs(la) > fabs(lb)) {
		a = Point(-lc/la, 0.0);
		b = Point(-(SETLEN*lb+lc)/la, SETLEN);
	}
	else {
		a = Point(0.0, -lc/lb);
		b = Point(SETLEN, -(lc+SETLEN*la)/lb);
	}
	CrossLineCircle(a, b, false, false, c1, r1);
}

typedef Point pnt;

int n, m;
pnt goats[2];
pnt water;

double Solve() {
	ans.clear();	
	double rad[2];
	rad[0] = !(goats[0] - water);
	rad[1] = !(goats[1] - water);
	CrossCircleCircle(goats[0], rad[0], goats[1], rad[1]);
	double area = 0.0;
	for (int u = 0; u<2; u++) {
		double a[2];
		assert(ans.size() == 2);
		for (int t = 0; t<2; t++) a[t] = ~(ans[t] - goats[u]);

		if (a[0] > a[1]) std::swap(a[0], a[1]);
		double diff = a[1] - a[0];

		double mid = (a[0] + a[1]) / 2;
        pnt p = goats[u] + pnt(cos(mid), sin(mid)) * rad[u];
        if (EpsGreater(!(p - goats[!u]), rad[!u])) diff = 2*PI - diff;

        area += rad[u]*rad[u] * (diff - sin(diff));
	}
	return area / 2.0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i<n; i++) scanf("%lf%lf", &goats[i].x, &goats[i].y);

		printf("Case #%d: ", tt);
		fflush(stdout);
		for (int i = 0; i<m; i++) {
			if (i) printf(" ");
			scanf("%lf%lf", &water.x, &water.y);
			double ret = Solve();
			printf("%0.10lf", ret);
		}
		printf("\n");
	}
	return 0;
}

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXM = 10;
const double EPS = 1e-8;
const double PI = atan2(0.0, -1.0);

struct Point {
	double x, y;
};

inline double getDis(const Point & a, const Point & b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

Point intersection(const Point & u1, const Point & u2, const Point & v1, const Point & v2) {
	Point ret = u1;
	double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
	ret.x += (u2.x - u1.x) * t;
	ret.y += (u2.y - u1.y) * t;
	return ret;
}

void intersectionLineCircle(const Point & c, double r, const Point & l1, const Point & l2, Point & p1, Point & p2) {
	Point p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = intersection(p, c, l1, l2);
	double t = sqrt(r * r - getDis(p, c) * getDis(p, c)) / getDis(l1, l2);
	p1.x = p.x + (l2.x - l1.x) * t;
	p1.y = p.y + (l2.y - l1.y) * t;
	p2.x = p.x - (l2.x - l1.x) * t;
	p2.y = p.y - (l2.y - l1.y) * t;
}

void intersectionCircleCircle(const Point & c1, double r1, const Point & c2, double r2, Point & p1, Point & p2) {
	Point u, v;
	double t = (1 + (r1 * r1 - r2 * r2) / getDis(c1, c2) / getDis(c1, c2)) / 2;
	u.x = c1.x + (c2.x - c1.x) * t;
	u.y = c1.y + (c2.y - c1.y) * t;
	v.x = u.x + c1.y - c2.y;
	v.y = u.y - c1.x + c2.x;
	intersectionLineCircle(c1, r1, u, v, p1, p2);
}

inline double getInsideArea(const Point & ca, double ra, const Point & cb, double rb, const Point & p1, const Point & p2) {
	double a1 = atan2(p1.y - ca.y, p1.x - ca.x);
	double a2 = atan2(p2.y - ca.y, p2.x - ca.x);
	double am = (a1 + a2) * 0.5;
	Point mid;
	mid.x = cos(am) * ra + ca.x;
	mid.y = sin(am) * ra + ca.y;
	double ang;
	if (getDis(mid, cb) <= rb + EPS) {
		ang = abs(a2 - a1);
	} else {
		ang = 2 * PI - abs(a2 - a1);
	}
	double tri = sin(ang) * ra * ra * 0.5;
	//if (ang <= PI + EPS) {
		return ra * ra * ang * 0.5 - tri;
	//} else {
	//	return ra * ra * ang * 0.5 + tri;
	//}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	Point ca, cb;
	Point aims[MAXM];
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%lf%lf%lf%lf", &ca.x, &ca.y, &cb.x, &cb.y);
		for (int i = 0; i < m; i++) {
			scanf("%lf%lf", &aims[i].x, &aims[i].y);
		}
		printf("Case #%d:", caseIndex);
		double dis = getDis(ca, cb);
		for (int i = 0; i < m; i++) {
			double ra = getDis(ca, aims[i]);
			double rb = getDis(cb, aims[i]);
			double ans;
			if (ra + rb - EPS <= dis) {
				ans = 0.0;
			} else if (dis <= abs(ra - rb) + EPS) {
				ans = min(ra, rb) * min(ra, rb) * PI;
			} else {
				Point p1, p2;
				intersectionCircleCircle(ca, ra, cb, rb, p1, p2);
				ans = getInsideArea(ca, ra, cb, rb, p1, p2);
				ans += getInsideArea(cb, rb, ca, ra, p1, p2);
			}
			printf(" %.8lf", ans);
		}
		putchar('\n');
	}
	return 0;
}

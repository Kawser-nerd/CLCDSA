#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
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

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const double EPS = 1E-8;

bool zero(double x) { return -EPS < x && x < EPS; }
int sgn(double x) { return x > EPS ? 1 : (x < -EPS ? -1 : 0); }

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	void init() { scanf("%lf%lf", &x, &y); }
	void print() const { printf("Point(%lf %lf)\n", x, y); }
	bool operator < (const Point & rhs) const { return x < rhs.x - EPS || (zero(x - rhs.x) && y < rhs.y - EPS); }
	bool operator == (const Point & rhs) const { return zero(x - rhs.x) && zero(y - rhs.y); }
	Point operator - (const Point & rhs) const { return Point(x - rhs.x, y - rhs.y); }
	Point operator + (const Point & rhs) const { return Point(x + rhs.x, y + rhs.y); }
	Point operator * (const double scale) const { return Point(x * scale, y * scale); }
	Point operator / (const double scale) const { return Point(x / scale, y / scale); }
	double operator * (const Point & rhs) const { return x * rhs.y - rhs.x * y; }
	double operator ^ (const Point & rhs) const { return x * rhs.x + y * rhs.y; }
	Point rotate(double angle) const { Point p(sin(angle), cos(angle)); return Point((*this) * p, (*this) ^ p); }
	double length2() const { return x * x + y * y; }
	double length() const { return sqrt(this->length2()); }
	Point trunc(const double scale) const { return (*this) / this->length() * scale; }
	double angle() const { return atan2(y, x); }
	Point perpendicular() const { return Point(-y, x); }
};

struct Line {
	Point l1, l2;
	Line() {}
	Line(Point l1, Point l2) : l1(l1), l2(l2) {}
	void init() { l1.init(); l2.init(); }
	void print() const { printf("Line[(%lf %lf)--(%lf %lf)]\n", l1.x, l1.y, l2.x, l2.y); }
	bool cross(const Point & p) const { return zero((p - l2) * (l1 - l2)); }
	bool cross(const Line &rhs) const { return !this->parallel(rhs); }
	bool parallel(const Line &rhs) const { return zero((l1 - l2) * (rhs.l1 - rhs.l2)); }
	Point intersection(const Line &rhs) const { return l1 + (l2 - l1) * (((l1 - rhs.l1) * (rhs.l1 - rhs.l2)) / ((l1 - l2) * (rhs.l1 - rhs.l2))); }
	Point projection(const Point &p) const { return this->intersection(Line(p, p + (l1 - l2).perpendicular())); }
	double distance(const Point &p) const { return fabs((p - l1) * (l2 - l1)) / (l1 - l2).length(); }
};

double area(int n, Point *p) {
	p[n] = p[0];
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += p[i + 1] * p[i];
	}
	return fabs(res) / 2;
}

double area(vector<Point> &p) {
	int n = p.size();
	p.push_back(p.front());
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += p[i + 1] * p[i];
	}
	p.pop_back();
	return fabs(res) / 2;
}

int graham(int n, Point *p, Point *ch, bool comEdge = false) {
    if (n < 3) {
		for (int i = 0; i < n; i++) ch[i] = p[i];
		return n;
	}
    const double e1 = comEdge ? EPS : -EPS;
	int i, j, k;
    sort(p, p + n);
	ch[0] = p[0];
	ch[1] = p[1];
    for(i = j = 2; i < n; ch[j++] = p[i++]) 
		while(j > 1 && (ch[j - 2] - ch[j - 1]) * (p[i] - ch[j - 1]) > e1) j--;
    ch[k = j++] = p[n - 2];
    for(i = n - 3; i > 0; ch[j++] = p[i--]) 
		while(j > k && (ch[j - 2] - ch[j - 1]) * (p[i] - ch[j - 1]) > e1) j--;
    while (j > k && (ch[j - 2] - ch[j - 1]) * (ch[0] - ch[j - 1]) > e1) j--;
    return j;
}

const int MAXN = 20;

bool found;
int n, m;
double S;
Point point[MAXN], p[MAXN], convex[MAXN];
int prev[MAXN], next[MAXN];
vector<Point> v;
vector<int> idx;

int decideSide(const Point & p1, const Point & p2, const Point & l1, const Point & l2) {
	return sgn((l1 - l2) * (p1 - l2)) * sgn((l1 - l2) * (p2 - l2));
}

bool dotsInline(const Point & p1, const Point & p2, const Point & p3) {
	return zero((p1 - p3) * (p2 - p3));
}

bool dotOnlineIn(const Point & p, const Point & l1, const Point & l2) {
	return zero((p - l2) * (l1 - l2)) 
		&& (l1.x - p.x) * (l2.x - p.x) < EPS 
		&& (l1.y - p.y) * (l2.y - p.y) < EPS;
}

bool intersectIn(const Point & u1, const Point & u2, const Point & v1, const Point & v2) {
	if (!dotsInline(u1, u2, v1) || 
		!dotsInline(u1, u2, v2)) {
		return decideSide(u1, u2, v1, v2) != 1 
			&& decideSide(v1, v2, u1, u2) != 1;
	} else {
		return dotOnlineIn(u1, v1, v2) 
			|| dotOnlineIn(u2, v1, v2) 
			|| dotOnlineIn(v1, u1, u2) 
			|| dotOnlineIn(v2, u1, u2);
	}
}

void dfs(int depth) {
//printf("depth = %d\n", depth);
//printf("idx ="); FOR(i, 0, depth) printf(" %d", idx[i]); putchar('\n');
	if (depth == n) {
		bool flag = true;
		for (int j = 2; j < n - 1; j++) if (intersectIn(v[j - 1], v[j], v[0], v[n - 1])) {
			flag = false;
			break;
		}
		if (flag && area(v) > S / 2 + EPS) found = true;
		return ;
	}
	for (int i = next[0]; i <= n; i = next[i]) {
		v.push_back(point[i - 1]);
		idx.push_back(i - 1);
		bool flag = true;
		for (int j = 1; j <= depth - 2; j++) if (intersectIn(v[j - 1], v[j], v[depth - 1], v[depth])) {
			flag = false;
			break;
		}
		if (flag) {
			prev[next[i]] = prev[i];
			next[prev[i]] = next[i];
			dfs(depth + 1);
			if (found) return ;
			prev[next[i]] = next[prev[i]] = i;
		}
		v.pop_back();
		idx.pop_back();
	}
}

int main() {
	int taskNumber; scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		scanf("%d", &n);
		FOR(i, 0, n) {
			point[i].init();
			p[i] = point[i];
		}
		m = graham(n, p, convex);
		S = area(m, convex);
		FOR(i, 0, n + 2) {
			next[i] = i + 1;
			prev[i] = i - 1;
		}
		found = false;
		v.clear();
		idx.clear();
		dfs(0);
		printf("Case #%d:", taskIdx);
		FOR(i, 0, n) printf(" %d", idx[i]);
		putchar('\n');
	}
	return 0;
}

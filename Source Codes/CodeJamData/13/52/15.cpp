#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

struct Point {
	int x, y;
	int name;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	Point operator- (Point b) const { return Point(x-b.x, y-b.y); }
	int64 operator! () const { return int64(x)*x + int64(y)*y; }

	bool operator< (Point oth) {
		if (x != oth.x) return x < oth.x;
		return y < oth.y;
	}
};

int64 dot(Point a, Point b) {
	return int64(a.x) * b.x + int64(a.y) * b.y;
}
int64 cross(Point a, Point b) {
	return int64(a.x) * b.y - int64(a.y) * b.x;
}

const int SIZE = 1024;

bool Intersect(Point a, Point b, Point c, Point d) {
	int64 det = cross(b-a, d-c);
	int64 detu = cross(c-a, d-c);
	int64 detv = cross(c-a, b-a);
	if (det == 0) return false;
    if (det < 0) {
		det = -det;
		detu = -detu;
		detv = -detv;
    }
    return detu >= 0 && detu <= det && detv >= 0 && detv <= det;
}

bool LiesOn(Point a, Point s, Point t) {
	return cross(a-s, t-s) == 0 && dot(a-s, t-s) >= 0 && dot(a-t, s-t) >= 0;
}

Point ctr;
struct CmpVerts {
	bool operator() (Point a, Point b) const {
		int64 qq = cross(a-ctr, b-ctr);
		if (qq != 0) return qq < 0;
		int64 ad = !(a-ctr);
		int64 bd = !(b-ctr);
		return ad < bd;
	}
};

int n;
Point pts[SIZE];
int perm[SIZE];
Point hull[SIZE];
int h;

int64 ans;
Point best[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) {
			scanf("%d%d", &pts[i].x, &pts[i].y);
			pts[i].name = i;
		}

		int lm = 0;
		for (int i = 0; i<n; i++)
			if (pts[i].x < pts[lm].x || pts[i].x == pts[lm].x && pts[i].y < pts[lm].y)
				lm = i;

		swap(pts[0], pts[lm]);
		ctr = pts[0];
		sort(pts+1, pts+n, CmpVerts());

		h = 3;
		hull[0] = pts[0];
		hull[1] = pts[1];
		hull[2] = pts[2];
		for (int i = 3; i<n; i++) {
			while (h > 2 && cross(hull[h-1]-hull[h-2], pts[i]-hull[h-1]) >= 0) h--;
			hull[h++] = pts[i];
		}

		int64 fullarea = 0;
		for (int i = 0; i<h; i++) fullarea += cross(hull[i], hull[(i+1)%h]);
		if (fullarea < 0) fullarea = -fullarea;


		ans = -1;
		sort(pts, pts+n);
		do {
			bool ok = true;
			for (int i = 0; i<n; i++)
				for (int j = i+1; j<n; j++) {
					if (i == j || i == (j+1)%n || (i+1)%n == j || (i+1)%n == (j+1)%n)
						continue;
					if (Intersect(pts[i], pts[(i+1)%n], pts[j], pts[(j+1)%n]))
						ok = false;
				}
			for (int i = 0; i<n; i++)
				for (int j = 0; j<n; j++) {
					if (i == j || i == (j+1)%n)
						continue;
					if (LiesOn(pts[i], pts[j], pts[(j+1)%n]))
						ok = false;
				}

			if (ok) {
				int64 tres = 0;
				for (int i = 0; i<n; i++) tres += cross(pts[i], pts[(i+1)%n]);
				if (tres < 0) tres = -tres;

				if (ans < tres) {
					ans = tres;
					memcpy(best, pts, n*sizeof(pts[0]));
					if (2*ans > fullarea) break;
				}
			}
		} while (std::next_permutation(pts, pts+n));

//		printf("%I64d / %I64d\n", ans, fullarea);
		assert(ans <= fullarea);
		printf("Case #%d:", tt);
		for (int i = 0; i<n; i++) printf(" %d", best[i].name);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}

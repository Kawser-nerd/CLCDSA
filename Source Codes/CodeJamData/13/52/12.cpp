#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n, x[maxN], y[maxN];

struct point {
	long long x, y;
	point() {
	}
	point(long long x, long long y) : x(x), y(y) {
	}
};

bool cmp(point a, point b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector < point >& a) {
	if (a.size() == 1) {
		return;
	}
	sort (a.begin(), a.end(), &cmp);
	point p1 = a[0],  p2 = a.back();
	vector <point> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (int i = 1; i < a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i])) {
				up.pop_back();
			}
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i])) {
				down.pop_back();
			}
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (int i = 0; i < up.size(); ++i) {
		a.push_back(up[i]);
	}
	for (int i = down.size() - 2; i > 0; --i) {
		a.push_back(down[i]);
	}
}

long long area (point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (point a, point b, point c, point d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

long long getArea(vector < point >& a) {
	int n = a.size();
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res += a[i].x * a[(i + 1) % n].y - a[(i + 1) % n].x * a[i].y;
	}
	return (res > 0 ? res : -res);
}

void solve(int test) {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	vector < point > a;
	for (int i = 0; i < n; ++i) {
		a.push_back(point(x[i], y[i]));
	}

	convex_hull(a);
	long long need = getArea(a);

	vector < int > order(n);
	for (int i = 0; i < n; ++i) {
		order[i] = i;
	}

	do {
		vector < point > a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = point(x[order[i]], y[order[i]]);
		}
		long long A = getArea(a);
		if (A + A <= need) {
			continue;
		}

		bool nice = true;
		for (int i = 0; i < n && nice; ++i) {
			for (int j = i + 1; j < n && nice; ++j) {
				if ((i + 1) % n == j || (i + 1) % n == (j + 1) % n) {
					continue;
				}
				if (i == j || i == (j + 1) % n) {
					continue;
				}

				if (intersect(a[i], a[(i + 1) % n], a[j], a[(j + 1) % n])) {
					nice = false;
				}
			}
		}

		if (nice) {
			printf("Case #%d:", test);
			for (int i = 0; i < n; ++i) {
				printf(" %d", order[i]);
			}
			printf("\n");
			return ;
		}
	} while (next_permutation(order.begin(), order.end()));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		cerr << i << endl;
	}

	return 0;
}
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-7;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

struct Point {
	double x, y;
	Point(double x=0, double y=0) : x(x), y(y) {}
};

vector<Point> intersectCircleCircle(Point m1, double r1, Point m2, double r2) {
    vector<Point> res;
    double dx = m2.x - m1.x, dy = m2.y - m1.y;
    double d = sqrt(dx*dx + dy*dy);
    double rsum = r1 + r2, rdiff = abs(r1 - r2);
    if (d > rsum || d < rdiff || (d < eps && rdiff < eps)) return res;
    double x = (d*d + r1*r1 - r2*r2) / (2*d);
    if (abs(d - rsum) < eps || abs(d - rdiff) < eps) {
        res.push_back(Point(m1.x + (x*dx)/d, m1.y + (x*dy)/d));
    } else {
        double y = sqrt(abs(r1*r1 - x*x));
        res.push_back(Point(m1.x + (x*dx - y*dy) / d, m1.y + (x*dy + y*dx) / d));
        res.push_back(Point(m1.x + (x*dx + y*dy) / d, m1.y + (x*dy - y*dx) / d));
    }
    return res;
}

int C, N;
Point M[50];
double R[50];
double RR[50];
vector<Point> S;
vector<long long> masks;

double dist(Point a, Point b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

bool check(double r) {
	FOR(i, 0, N) RR[i] = r - R[i];
	S.clear();
	FOR(i, 0, N) S.push_back(M[i]);
	FOR(i, 0, N) FOR(j, i+1, N) {
		vector<Point> v = intersectCircleCircle(M[i], RR[i], M[j], RR[j]);
		FOR(k, 0, sz(v)) S.push_back(v[k]);
	}
	masks.clear();
	FOR(i, 0, sz(S)) {
		long long m = 0;
		FOR(j, 0, N) {
			if (dist(S[i], M[j]) <= RR[j] + eps) {
				m |= (1LL << j);
			}
		}
		masks.push_back(m);
	}
	FOR(i, 0, sz(masks)) FOR(j, i, sz(masks)) {
		if ((masks[i] | masks[j]) == ((1LL << N) - 1)) return true;
	}
	return false;
}

int main() {
	cin >> C;
	FOR(cs, 1, C+1) {
		cin >> N;
		FOR(i, 0, N) cin >> M[i].x >> M[i].y >> R[i];
		double a = 0;
		FOR(i, 0, N) a = max(a, R[i]);
		double b = 2*a;
		while (!check(b)) {
			a = b;
			b *= 2;
		}
		while (b - a >= eps) {
			double m = (a + b) / 2;
			if (check(m)) {
				b = m;
			} else {
				a = m;
			}
		}
		printf("Case #%d: %.6lf\n", cs, a);
	}
	return 0;
}

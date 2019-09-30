#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

typedef double D;
const D eps = 1E-11;

struct P {
	D x, y;
	P(D x = 0.0, D y = 0.0) : x(x), y(y) {} 
	P operator+(P a) {
		return P(x + a.x, y + a.y);
	}
	P operator-(P a) {
		return P(x - a.x, y - a.y);
	}
	P operator*(D k) {
		return P(x * k, y * k);
	}
	D operator *(P a) {
		return x * a.y - y * a.x;
	}
	D operator ^(P a) {
		return x * a.x + y * a.y;
	}
	D len() {
		return sqrt(x * x + y * y);
	}
	P perp() {
		return P(y, -x);
	}
	P norm() {
		D l = len();
		return abs(l) < eps ? P(x, y) : P(x / l, y / l);
	}
	bool operator==(P a) {
		return abs(x - a.x) < eps && abs(y - a.y) < eps;
	}
	void load() {
		cin >> x >> y;
	}
};

int sgn(D x)
{
	if (x > eps) return 1;
	if (x < -eps) return -1;
	return 0;
}

bool pointOnSegment(P p, P a, P b) {
	if (abs((a - p) * (b - p)) > eps) 
		return false;
	return ((a - p) ^ (b - p)) < eps;
}

bool crossSegments1d(D a, D aa, D b, D bb) {
	return min(a, aa) < max(b, bb) + eps && min(b, bb) < max(a, aa) + eps;	
}

bool crossSegments(P a, P aa, P b, P bb) {
	if (sgn((b - a) * (aa - a)) * sgn((aa - a) * (bb - a)) < 0)
		return false;
	if (sgn((a - b) * (bb - b)) * sgn((bb - b) * (aa - b)) < 0)
		return false;
	return crossSegments1d(a.x, aa.x, b.x, bb.x) && crossSegments1d(a.y, aa.y, b.y, bb.y);
}

struct L {
	D a, b, c;
	L(D a = 0.0, D b = 0.0, D c = 0.0): a(a), b(b), c(c) {}
};

L getLine(P p1, P p2) {
	D x0 = p1.x, y0 = p1.y;
	D al = (p2 - p1).x, be = (p2 - p1).y;
	return L(be, -al, al * y0 - be * x0);
}

P getP(L l1, L l2) {
	D det = l1.a * l2.b - l1.b * l2.a;
	D det1 = -(l1.c * l2.b - l1.b * l2.c);
	D det2 = -(l1.a * l2.c - l1.c * l2.a);
	return P(det1 / det, det2 / det);
}

vector<P> l, u;
D w;

D getArea(D x1, D x2) {
	vector<P> l = (::l);
	vector<P> u = (::u);
	vector<P> w;
	for (int it = 0; it < 2; ++it) {
		vector<P> v;
		for (int i = 0; i < sz(l); ++i) {
			if (l[i].x > x1 - eps && l[i].x < x2 + eps) {
				if (i > 0 && l[i - 1].x < x1 + eps) {
					L l1 = getLine(l[i - 1], l[i]);
					L l2(1, 0, -x1);
					v.pb(getP(l1, l2));
				}			
				v.pb(l[i]);
				if (i + 1 < sz(l) && l[i + 1].x > x2 - eps) {
					L l1 = getLine(l[i + 1], l[i]);
					L l2(1, 0, -x2);
					v.pb(getP(l1, l2));
				}
				continue;
			}
			if (i + 1 < sz(l) && l[i].x < x1 + eps && l[i + 1].x > x2 - eps) {
				L l1 = getLine(l[i + 1], l[i]);
				L l2(1, 0, -x1);
				v.pb(getP(l1, l2));
				l1 = getLine(l[i], l[i + 1]);
				l2 = L(1, 0, -x2);
				v.pb(getP(l1, l2));
			}
		}
		if (it == 1) reverse(all(v));
		for (int i = 0; i < sz(v); ++i)
			w.pb(v[i]);
		l = u;
	}
	D res = 0.0;
	for (int i = 0; i < sz(w); ++i) {
		int j = (i + 1) % sz(w);
		res += w[i] * w[j];
	}
	return abs(res);
}

void solve() {
	int nl, nu;
	int g;
	cin >> w >> nl >> nu >> g;
	l = vector<P>(nl), u = vector<P>(nu);
	for (int i = 0; i < nl; ++i)
		l[i].load();
	for (int i = 0; i < nu; ++i)
		u[i].load();
	double s = getArea(0, w);
	s /= g;
	D last = 0.0;
	for (int it = 0; it < g - 1; ++it) {
		double down = last, up = w;
		for (int IT = 0; IT < 100; ++IT) {
			D t = (up + down) * 0.5;
			if (getArea(last, t) < s)
				down = t;
			else
				up = t;
		}
		D res = (up + down) * 0.5;
		printf("%.12lf\n", res);
		last = res;
	}
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		printf("Case #%d:\n", it + 1);
		solve();
	}
	return 0;
}

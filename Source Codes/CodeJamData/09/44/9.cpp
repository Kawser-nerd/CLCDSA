//	GCJ 2009 Round 2 (D)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; while ((c = getchar()) <= ' ') { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	while ((uint)((c = getchar()) - '0') >= 10) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}


const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
inline int sig(double r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }

struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator/(const Pt &a) { return Pt(dot(a) / a.norm(), -det(a) / a.norm()); }
	Pt operator-() { return Pt(-x, -y); }
	Pt operator*(const double &k) { return Pt(x * k, y * k); }
	Pt operator/(const double &k) { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double norm() const { return x * x + y * y; }
	double dot(Pt a) const { return x * a.x + y * a.y; }
	double det(Pt a) const { return x * a.y - y * a.x; }
};
namespace std {
	bool operator<(const Pt &a, const Pt &b) { return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y); }
	bool operator==(const Pt &a, const Pt &b) { return (sig(a.x - b.x) == 0) && (sig(a.y - b.y) == 0); }
	ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
}
inline double tri(Pt a, Pt b, Pt c) { return (b - a).det(c - a); }


int iCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	if (sig(d) == 0 && sig(r - s) == 0) return -1;	//	correspond
	if (sig(r - s - d) > 0) return 2;	//	r > s
	if (sig(s - r - d) > 0) return -2;	//	s > r
	return (sig(r + s - d) >= 0) ? 1 : 0;
}
pair<Pt,Pt> pCC(Pt a, double r, Pt b, double s) {
	double d = (b - a).abs();
	double x = (d * d + r * r - s * s) / (d * 2);
//	double y = sqrt(r * r - x * x + EPS);
	double y = sqrt(max(r * r - x * x, 0.0));
	Pt e = (b - a) / d;
	return mp(a + e * x + e * Pt(0, 1) * y, a + e * x - e * Pt(0, 1) * y);
}


const double EPS2 = 1e-6;

typedef unsigned long long ulong;
ulong WIN;

int N;
Pt P[50];
double RR[50], R[50];

int M;
ulong cov[3010];

ulong check(Pt q) {
//cout<<"check "<<q<<endl;
	ulong ret = 0;
	int i;
	for (i = 0; i < N; ++i) {
		if ((P[i] - q).norm() <= R[i] * R[i] + EPS2) {
			ret |= 1uLL << i;
		}
	}
	return ret;
}

bool ok(double spr) {
//cout<<"spr = "<<spr<<endl;
	int i, j;
	pair<Pt,Pt> res;
	
	for (i = 0; i < N; ++i) {
		R[i] = spr - RR[i];
	}
	
	M = 0;
	for (i = 0; i < N; ++i) {
		cov[M++] = check(P[i]);
	}
	for (i = 0; i < N; ++i) for (j = i + 1; j < N; ++j) {
		if (iCC(P[i], R[i], P[j], R[j]) == 1) {
			res = pCC(P[i], R[i], P[j], R[j]);
			cov[M++] = check(res.first);
			cov[M++] = check(res.second);
		}
	}
//pv(cov,cov+M);
	
	for (i = 0; i < M; ++i) for (j = i; j < M; ++j) {
		if ((cov[i] | cov[j]) == WIN) return 1;
	}
	
	return 0;
}

int main() {
	int i;
	double lo, ho;
	
	for (int TC = in(), tc = 0; TC--; ) {
		N = in();
		lo = 0;
		ho = 1000;
		for (i = 0; i < N; ++i) {
			P[i].x = in();
			P[i].y = in();
			RR[i] = in();
			if (lo < RR[i]) lo = RR[i];
		}
		
		WIN = (1uLL << N) - 1;
		
		for (int reps = 40; reps--; ) {
			double mo = (lo + ho) * 0.5;
			ok(mo) ? ho = mo : lo = mo;
		}
		
		printf("Case #%d: %.8f\n", ++tc, ho);
		
	}
	
	
	return 0;
}


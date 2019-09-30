#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef double D;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

template<class T> T sqr(T x) { return x * x;            }
template<class T> T abs(T x) { return (x > 0) ? x : -x; }

struct P {
	D x, y;

	P() {}
	P(D x, D y): x(x), y(y) {}

	P operator + (P a) { return P(x + a.x, y + a.y); }
	P operator - (P a) { return P(x - a.x, y - a.y); }
	P operator * (D a) { return P(x * a, y * a); }
	D operator * (P a) { return x * a.y - y * a.x;   }
	D operator ^ (P a) { return x * a.x + y * a.y;   }

	D len2() { return sqr(x) + sqr(y); }
	D len()  { return sqrt(len2());    }
	P orth() { return P(y, -x);        }

	void load() {
		cin >> x >> y;
	}
};

struct L {
	D a, b, c;

	L() {}
	L(D a, D b, D c): a(a), b(b), c(c) {}
	L(P p1, P p2) {
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = -p1.x * a - p1.y * b;
	}
};

struct C {
	P c;
	D r;

	C() {}
	C(P c, D r): c(c), r(r) {}
};

P doit(P p1, P p2, P p3) {
	D a = p1.x, b = p2.x, c = p3.x;
	D d = p1.y, e = p2.y, f = p3.y;
	D dd = a * e - b * d;
	D dx = c * e - b * f;
	D dy = a * f - c * d;
	return P(dx / dd, dy / dd);
}

void solve(int it) {
	P p1, p2, p3, p4, p5, p6;
	p1.load();
	p2.load();
	p3.load();
	p4.load();
	p5.load();
	p6.load();
	P alpha = (p2 - p1) - (p5 - p4);
	P beta = (p3 - p1) - (p6 - p4);
	P gamma = p4 - p1;
	P a = doit(alpha, beta, gamma);
	P ans = p1 + (p2 - p1) * a.x + (p3 - p1) * a.y;
	printf("Case #%d: ", it);
	printf("%.10lf %.10lf\n", ans.x, ans.y);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; it++) {
		solve(it);
	}
	return 0;
}

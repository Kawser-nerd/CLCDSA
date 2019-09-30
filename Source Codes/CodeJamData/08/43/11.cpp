#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<double,double> pdd;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

bool seekEoln() {
	int ch;
	for (;;) {
		ch = getc(stdin);
		if (ch != ' ')
			break;
	}
	ungetc(ch, stdin);
	return ch == '\r' || ch == '\n' || ch == -1;
}

#ifndef _DEBUG
#define assert(f) if (!(f)) printf("\n%s\n", "ASSERTION FAILED!");
#endif

char buf[1024*1024];

int rd() {
	int x;
	bool f = scanf("%d", &x) == 1;
	assert(f);
	return x;
}

double rlf() {
	double x;
	bool f = scanf("%lf", &x) == 1;
	assert(f);
	return x;
}

string rs() {
	bool f = scanf("%s", buf) == 1;
	assert(f);
	return buf;
}

vi rvi() {
	int n;
	bool f = scanf("%d", &n) == 1;
	assert(f);
	vi x(n);
	Rep(i, n) {
		f = scanf("%d", &x[i]) == 1;
		assert(f);
	}
	return x;
}

void print(const vi& v) {
	Rep(i, Size(v)) {
		if (i > 0)
			printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
}

int n;
double x[1000], y[1000], z[1000], p[1000];
double res;

double solve(double cx, double cy, double cz) {
	double cur = 0;
	Rep(i, n)
		checkMax(cur, (fabs(cx-x[i])+fabs(cy-y[i])+fabs(cz-z[i]))/p[i]);
	checkMin(res, cur);
	return cur;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests(rd());
	For(test, 1, numTests) {
		n = rd();
		Rep(i, n) {
			x[i] = rlf();
			y[i] = rlf();
			z[i] = rlf();
			p[i] = rlf();
		}
		res = 1e32;
		double cx = 0, cy = 0, cz = 0;
		double step = 100000;
		while (step > 1e-15) {
			const int dx[] = {-1,1,0,0,0,0};
			const int dy[] = {0,0,-1,1,0,0};
			const int dz[] = {0,0,0,0,-1,1};
			Rep(d, 6) {
				while (solve(cx+step*dx[d], cy+step*dy[d], cz+step*dz[d]) < solve(cx, cy, cz)) {
					cx += step*dx[d];
					cy += step*dy[d];
					cz += step*dz[d];
				}
			}
			step /= 2;
		}
		printf("Case #%d: %.12lf\n", test, res);
	}

	exit(0);
}

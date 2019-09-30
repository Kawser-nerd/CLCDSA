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

#define _CRT_SECURE_NO_WARNINGS
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

const double pi = 2*acos(0.0);
const double eps = 1e-9;

double asin2(double x) {
	double res = asin(max(-1.0, min(1.0, x)));
	assert(-pi/2 <= res && res <= pi/2);
	return res;
}

double inters(double x1, double y1, double x2, double y2, double r) {
	assert(x1 <= x2 && y1 <= y2);
	assert(sqrt(sqr(x1)+sqr(y1)) <= r);
	if (sqrt(sqr(x2)+sqr(y2)) <= r)
		return (x2-x1)*(y2-y1);
	vector<double> xs;
	xs.push_back(x1);
	xs.push_back(x2);	
	double x = sqrt(sqr(r)-sqr(y1));
	if (y1 < r && x1 < x && x < x2)
		xs.push_back(x);
	x = sqrt(sqr(r)-sqr(y2));
	if (y2 < r && x1 < x && x < x2)
		xs.push_back(x);
	if (x1 < r && r < x2)
		xs.push_back(r);
	sort(All(xs));
	double res = 0;
	Rep(i, Size(xs)-1) {
		double x1 = xs[i], x2 = xs[i+1];
		if (x1 > r-eps)
			break;
		double s1 = y1*(x2-x1), s2 = y2*(x2-x1);
		double s4 = (0.5*x2*sqrt(sqr(r)-sqr(x2))+0.5*sqr(r)*asin2(x2/r))-(0.5*x1*sqrt(sqr(r)-sqr(x1))+0.5*sqr(r)*asin2(x1/r));
		double s3 = -s4;
		res += max(0.0, min(s2, s4)-max(s1, s3));
	}
	assert(res <= (x2-x1)*(y2-y1));
	return res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);
	For(test, 1, t) {
		double f, R, t, r, g;
		scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
		double sum = 0;
		if (g > 2*f) {
			double x = r;
			while (x+f < R-t-f) {
				double y = r;
				while (sqrt(sqr(x+f)+sqr(y+f)) < R-t-f) {
					sum += inters(x+f, y+f, x+g-f, y+g-f, R-t-f);
					y += 2*r+g;
				}
				x += 2*r+g;
			}
		}
		printf("Case #%d: %.6lf\n", test, (pi*sqr(R)-4*sum)/(pi*sqr(R)));
	}

	exit(0);
}

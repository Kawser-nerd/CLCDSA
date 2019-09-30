#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double PI = acos(-1.0);
const double EPS = 1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline double mySqrt(double x)
{
	if (x < EPS) {
		return 0;
	}
	return sqrt(x);
}

inline int signum(double x)
{
	if (x < -EPS) {
		return -1;
	}
	return x > EPS;
}

struct Point
{
	double x, y;
	Point(){}
	Point(double x, double y): x(x), y(y){}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double norm(){
		return sqrt(x * x + y * y);
	}
	void rotate(double ang) {
		double co = cos(ang), si = sin(ang);
		double tx = x, ty = y;
		x = tx * co - ty * si;
		y = tx * si + ty * co;
	}
};

inline Point operator + (const Point &a,const Point &b) {return Point(a.x + b.x, a.y + b.y);}
inline Point operator - (const Point &a,const Point &b) {return Point(a.x - b.x, a.y - b.y);}
inline Point operator * (const Point &a,const double &b) {return Point(a.x * b, a.y * b);}
inline Point operator / (const Point &a,const double &b) {return Point(a.x / b, a.y / b);}
inline double det(const Point &a, const Point &b) {return a.x * b.y - a.y * b.x;}
inline double dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
//================================

inline bool strictlyOn(Point o, Point a, Point b)
{
	double length = (o - a).norm();
	if (signum(length) == 0) {
		return false;
	}
	return signum(det(o - a, o - b) / length) == 0 && signum(dot(o - a, o - b) / length) < 0;
}

inline bool on(Point o, Point a, Point b)
{
	double length = (o - a).norm();
	if (signum(length) == 0) {
		return true;
	}
	return signum(det(o - a, o - b) / length) == 0 && signum(dot(o - a, o - b) / length) <= 0;
}

inline bool intersect(Point a, Point b, Point c, Point d)
{
	double s1 = det(a - b, c - b);
	double s2 = det(a - b, d - b);
	if (signum(s1 - s2) == 0) {
		return false;
	}
	Point e = (c * s2 - d * s1) / (s2 - s1);
	return strictlyOn(e, a, b) && strictlyOn(e, c, d);
}

int main()
{
	int T, test = 1;
	for (scanf("%d", &T); test <= T; ++ test) {
		int n, id[20], ans[20];
		Point a[20], p[20];
		scanf("%d", &n);
		for (int i= 0; i < n; ++ i) {
			a[i].read();
			id[i] = i;
			ans[i] = i;
		}
		double maxi = 0;
		printf("Case #%d:", test);
		do{
			for (int i = 0; i < n; ++ i) {
				p[i] = a[id[i]];
			}
			p[n] = p[0];
			
			bool valid = true;
			for (int i = 0; i < n && valid; ++ i) {
				for (int j = 0; j < i; ++ j) {
					if (intersect(p[i], p[i + 1], p[j], p[j + 1])) {
						valid = false;
						break;
					}
				}
			}
			for (int i = 0; i < n && valid; ++ i) {
				int cnt = 0;
				for (int j = 0; j < n && cnt <= 2; ++ j) {
					if (on(p[i], p[j], p[j + 1])) {
						++ cnt;
					}
				}
				if (cnt > 2) {
					valid = false;
				}
			}
			if (valid) {
				double area = 0;
				for (int i = 0; i < n; ++ i) {
					area += det(p[i], p[i + 1]);
				}
				area = fabs(area) / 2;
				if (area > maxi) {
					maxi = area;
					memcpy(ans, id, sizeof(id));
				}
			}
		}while (next_permutation(id, id + n - 1));
		for (int i = 0; i < n; ++ i) {
			printf(" %d", ans[i]);
		}
		puts("");
		fprintf(stderr, "%.10f\n", maxi);
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const double INF = 1e18;
const double INF_D = 1e5;


const double inf = (double) 1e18;
const double eps = (double) 1e-9;

bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
	return x < y && !eq(x, y);
}
bool gr(double x, double y)
{
	return x > y && !eq(x, y);
}
bool lsEq(double x, double y)
{
	return x < y || eq(x, y);
}
bool grEq(double x, double y)
{
	return x > y || eq(x, y);
}


struct Point
{
	double x, y;
	Point() : x(), y() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	Point operator + (const Point &A) const { return Point(x + A.x, y + A.y); }
	Point operator - (const Point &A) const { return Point(x - A.x, y - A.y); }
	double operator % (const Point &A) const { return x * A.x + y * A.y; }
	double operator * (const Point &A) const { return x * A.y - y * A.x; }
	double length() const { return sqrt(*this % *this); }
	Point operator * (const double &a) const { return Point(x * a, y * a); }
	Point operator / (const double &a) const { return Point(x / a, y / a); }

	Point normalize() const
	{
		return *this / length();
	}
	Point negate() const
	{
		return Point(-x, -y);
	}
	Point rotate() const
	{
		return Point(-y, x);
	}
	Point distTo(const Point &A) const
	{
		return (*this - A).length();
	}

	bool operator < (const Point &A) const 
	{ 
		if (x != A.x) 
			return x < A.x; 
		return y < A.y; 
	}
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
	void eprint()
	{
		eprintf("%lf %lf\n", x, y);
	}
};



struct Ast
{
	Point P, v;

	Ast() : P(), v() {}

	void read()
	{
		P.read();
		v.read();
	}
};

bool intersectCircleLine(Point O, double R, Point A, Point B, Point &L, Point &R)
{
	Point P = O.getH(A, B);
	double h = O.distTo(P);
	if (h > R) return false;
	double x = sqrt(R * R - h * h);
	Point v = (B - A).normalize() * x;
	L = P + v;
	R = P - v;
	return true;
}

const int N = 1005;
Ast ast[N];
int n;
double s;

struct Event
{
	double x;
	int type, a, b;
	Event() : x(), type(), a(), b() {}
	Event(double _x, int _type, int _a, int _b) : x(_x), type(_type), a(_a), b(_b) {}

	bool operator < (const Event &A) const
	{
		return x < A.x;
	}
};

vector <Event> ev;

void addSegment(int a, int b, double l, double r)
{
	ev.push_back(Event(l, 1, a, b) );	
	ev.push_back(Event(l, -1, a, b) );
}

void init()
{
	ev.clear();
}

double lastJumpHere[N];
set <int> g[N];


bool solve(double dist)
{
	init();

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			Point st = ast[i].P - ast[j].P;
			Point v = ast[i].v - ast[j].v;
			v = v.normalize();
			if (v == Point() )
			{
				if (st.length() <= dist)
					addSegment(i, j, 0, INF);
				continue;
			}
			Point A, B;
			if (!intersectCircleLine(Point(), dist, st, st + v, A, B) )
				continue;
			double l = (A - st) % v;
			double r = (B - st) % v;
			if (l > r)
				swap(l, r);
			if (ls(r, 0) ) continue;
			l = max(l, 0);
			r = max(r, 0);
			addSegment(i, j, l, r);
		}

	sort(ev.begin(), ev.end() );
}

void solve()
{
	scanf("%d%lf", &n, &s);
	for (int i = 0; i < n; i++)
		ast[i].read();
	double l = 0, r = INF_D;

	for (int it = 0; it < IT; it++)
	{
		double m = (l + r) / 2;
		if (solve(m) )
			l = m;
		else
			r = m;
	}
	printf("%.10lf\n", r);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}



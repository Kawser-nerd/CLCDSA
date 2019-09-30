#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

const long double eps = 1e-10;

class Point
{
public:
	long double x, y;
	Point(long double xx, long double yy)
	{
		x = xx;
		y = yy;
	}
	Point()
	{
		x = y = 0;
	}
};

Point operator+(const Point &a, const Point &b)
{
	Point c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Point operator-(const Point &a, const Point &b)
{
	Point c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

Point operator*(const Point &a, long double b)
{
	Point c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}

Point operator*(long double b, const Point &a)
{
	Point c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}

long double operator^(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}

long double Dist(const Point &a, const Point &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double operator*(const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}


class Circle
{
public:
	Point cent;
	long double rad;
};

class Line
{
public:
	Point p1, p2;
};

inline long double sqr(long double a)
{
	return a * a;
}

void AddIntersections(Circle c, Line a, vector<Point> &where)
{
	long double aa, bb, cc;
	aa = sqr(a.p2.x - a.p1.x) + sqr(a.p2.y - a.p1.y);
	bb = 2 * (a.p2.x - a.p1.x) * (a.p1.x - c.cent.x) + 2 * (a.p2.y - a.p1.y) * (a.p1.y - c.cent.y);
	cc = sqr(a.p1.x - c.cent.x) + sqr(a.p1.y - c.cent.y) - sqr(c.rad);
	if (fabs(aa) < eps) return;
	long double dd = bb * bb - 4 * aa * cc;
	if (dd < -eps) return;
	dd = sqrt(fabs(dd));
	long double t1, t2;
	t1 = (-bb - dd) / (2 * aa);
	t2 = (-bb + dd) / (2 * aa);
	Point p;
	p.x = a.p1.x + (a.p2.x - a.p1.x) * t1;
	p.y = a.p1.y + (a.p2.y - a.p1.y) * t1;
	where.push_back(p);
	p.x = a.p1.x + (a.p2.x - a.p1.x) * t2;
	p.y = a.p1.y + (a.p2.y - a.p1.y) * t2;
	where.push_back(p);
}

void AddIntersections(Circle c1, Circle c2, vector<Point> &where)
{
	long double a, b, c;
	a = 2 * c2.cent.x - 2 * c1.cent.x;
	b = 2 * c2.cent.y - 2 * c1.cent.y;
	c = sqr(c1.cent.x) + sqr(c1.cent.y) - sqr(c2.cent.x) - sqr(c2.cent.y) - sqr(c1.rad) + sqr(c2.rad);
	Line l;
	if (fabs(b) < eps)
	{
		if (fabs(a) < eps) return;
		l.p1.y = 0;
		l.p1.x = (-c) / a;
	}
	else
	{
		l.p1.x = 0;
		l.p1.y = (-c) / b;
	}
	l.p2.x = l.p1.x - b;
	l.p2.y = l.p1.y + a;
	AddIntersections(c1, l, where);
}

int n;
Circle plt[50];

void Load()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		plt[i].cent.x = x;
		plt[i].cent.y = y;
		plt[i].rad = r;
	}
}

bool Cover(long double r, Point &p, vector<int> nc)
{
	int i;
	for (i = 0; i < nc.size(); i++)
	{
		if (Dist(plt[nc[i]].cent, p) < r - plt[nc[i]].rad + eps) continue;
		return false;
	}
	return true;
}

bool Check(long double r, Point &p1)
{
	int i;
	vector<int> ncover;
	for (i = 0; i < n; i++)
	{
		if (Dist(plt[i].cent, p1) < r - plt[i].rad + eps) continue;
		ncover.push_back(i);
	}
	if (ncover.size() == 0) return true;
	int j, k;
	for (i = 0; i < ncover.size(); i++)
	{
		for (j = i + 1; j < ncover.size(); j++)
		{
			if (plt[ncover[i]].rad > r + eps || plt[j].rad > r + eps) continue;
			vector<Point> pnt;
			plt[ncover[i]].rad = r - plt[ncover[i]].rad;
			plt[ncover[j]].rad = r - plt[ncover[j]].rad;
			AddIntersections(plt[ncover[i]], plt[ncover[j]], pnt);
			plt[ncover[i]].rad = r - plt[ncover[i]].rad;
			plt[ncover[j]].rad = r - plt[ncover[j]].rad;
			for (k = 0; k < pnt.size(); k++)
			{
				if (Cover(r, pnt[k], ncover)) return true;
			}
		}
	}
	for (i = 0; i < ncover.size(); i++)
	{
		if (Cover(r, plt[ncover[i]].cent, ncover)) return true;
	}
	return false;
}

bool Can(long double r)
{
	// positions for first
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (plt[i].rad > r + eps || plt[j].rad > r + eps) continue;
			vector<Point> pnt;
			plt[i].rad = r - plt[i].rad;
			plt[j].rad = r - plt[j].rad;
			AddIntersections(plt[i], plt[j], pnt);
			plt[i].rad = r - plt[i].rad;
			plt[j].rad = r - plt[j].rad;
			for (k = 0; k < pnt.size(); k++)
			{
				if (Check(r, pnt[k]))
				{
					return true;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (Check(r, plt[i].cent)) return true;
	}
	return false;
}

void Solve()
{
	long double l, r;
	l = 0;
	r = 10000;
	int i;
	for (i = 0; i < 100; i++)
	{
		long double mid = (l + r) / 2;
		if (Can(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf", (double)l);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}
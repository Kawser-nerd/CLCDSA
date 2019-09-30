#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef vector<int> VI;
typedef pair<int, int> pii;
typedef long long ll;

#define EPS 1e-8

struct Point
{
	double x, y;
};

void Rotate(Point& p, double alpha)
{
	Point q;
	q.x = p.x * cos(alpha) - p.y * sin(alpha);
	q.y = p.x * sin(alpha) + p.y * cos(alpha);
	p = q;
}
void solve(int test)
{
	printf("Case #%d: ", test);
	Point p[3], q[3];
	forn(i, 3)
	{
		cin >> p[i].x >> p[i].y;
	}
	forn(i, 3)
	{
		cin >> q[i].x >> q[i].y;
	}
	Point v1 = p[0];
	Point v2 = q[0];
	forn(i, 3)
	{
		p[i].x -= v1.x;
		p[i].y -= v1.y;
		q[i].x -= v2.x;
		q[i].y -= v2.y;
	}
	double a1 = atan2(p[1].y, p[1].x);
	double a2 = atan2(q[1].y, q[1].x);
	forn(i, 3)
	{
		Rotate(p[i], -a1);
		Rotate(q[i], -a2);
	}
	double c1 = p[1].x;
	double c2 = q[1].x;
	forn(i, 3)
	{
		p[i].x /= c1;
		p[i].y /= c1;
		q[i].x /= c2;
		q[i].y /= c2;
	}
	forn(i, 3)
	{
		assert(abs(q[i].x - p[i].x) < EPS);
		assert(abs(q[i].y - p[i].y) < EPS);
	}

	Point t = v1;
	forn(it, 6000000)
	{
		t.x -= v1.x;
		t.y -= v1.y;
		Rotate(t, -a1);
		t.x /= c1;
		t.y /= c1;
		t.x *= c2;
		t.y *= c2;
		Rotate(t, a2);
		t.x += v2.x;
		t.y += v2.y;
//		printf("%.8lf %.8lf\n", t.x, t.y);
	}

	printf("%.8lf %.8lf\n", t.x, t.y);
}
int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);

	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
         	


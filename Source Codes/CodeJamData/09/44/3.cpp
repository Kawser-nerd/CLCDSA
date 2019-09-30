#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long long ll;

#define NMAX 45
#define KMAX 100005

const double EPS = 1e-9;

typedef long double ld;

int n;

struct Point
{
    double x, y;
};

struct Line
{
    double a, b, c;
};

Point p[NMAX];
double r[NMAX];

inline bool operator==(const Point& p1, const Point& p2)
{
    return abs(p1.x - p2.x) < EPS && abs(p1.y - p2.y) < EPS;
}

void crossCircleLine(Point c, ld r, Line l, vector<Point>& v)
{
    v.clear();
    l.c += l.a * c.x + l.b * c.y;

    ld D = r * r * (l.a * l.a + l.b * l.b) - l.c * l.c;
    if (D < -EPS) return;
    D = sqrtl(fabsl(D));

    Point p;
    p.x = (-l.a * l.c + l.b * D) / (l.a * l.a + l.b * l.b) + c.x;
    p.y = (-l.b * l.c - l.a * D) / (l.a * l.a + l.b * l.b) + c.y;
    v.pb(p);

    p.x = (-l.a * l.c - l.b * D) / (l.a * l.a + l.b * l.b) + c.x;
    p.y = (-l.b * l.c + l.a * D) / (l.a * l.a + l.b * l.b) + c.y;
    v.pb(p);
}

void crossCircles(Point c1, ld r1, Point c2, ld r2, vector<Point>& v)
{
    v.clear();
    if (c1 == c2) return;
    Line l;
    l.a = 2 * (c1.x - c2.x);
    l.b = 2 * (c1.y - c2.y);
    l.c = c2.x * c2.x - c1.x * c1.x + c2.y * c2.y - c1.y * c1.y + r1 * r1 - r2 * r2;

    crossCircleLine(c1, r1, l, v);
}

ll mask[KMAX];
ll pow2[NMAX];

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool inside(Point p1, double r1, Point p2, double r2)
{
    return dist(p1, p2) + r1 < r2 + EPS;
}
bool can(double R)
{
    forn(i, n)
    {
        if (R < r[i] + EPS) return false;
    }

    vector<Point> v;
    forn(i, n)
    {
        forn(j, i)
        {
            vector<Point> tmp;
            crossCircles(p[i], R - r[i], p[j], R - r[j], tmp); 
            forv(k, tmp) v.pb(tmp[k]);
        }
    }

    forn(i, n) v.pb(p[i]);

    forv(i, v)
    {
        mask[i] = 0;

        forn(j, n)
        {
            if (inside(p[j], r[j], v[i], R)) mask[i] |= pow2[j];
        }
    }


    forv(i, v)
    {
        if (mask[i] == pow2[n]-1) return true;
        forn(j, i)
        {
            if ((mask[i] | mask[j]) == pow2[n]-1)
            {
                return true;
            }
        }
    }

    return false;

}

void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d", &n);
    forn(i, n)
    {
        cin >> p[i].x >> p[i].y >> r[i];
    }

    double L = 0, R = 1e+10;

    forn(it, 60)
    {
        double mid = (L + R) / 2;
        if (can(mid)) R = mid; else L = mid;
    }

    printf("%.7lf\n", L);
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    pow2[0] = 1;
    for1(i, NMAX - 1)
    {
        pow2[i] = pow2[i-1] * 2;
    }
    int tc; scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}
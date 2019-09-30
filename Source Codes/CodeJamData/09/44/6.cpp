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
#include <ctime>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct Point
{
    ld x, y;
};

struct Line
{
    ld a, b, c;
};

const ld EPS = 1e-9;

#define NMAX 45

Point c[NMAX];
ld r[NMAX], r1[NMAX];
int n;
vector<Point> vp;

inline bool operator==(const Point& p1, const Point& p2)
{
    return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

void crossCircleLine(Point c, ld r, Line l, vector<Point>& v)
{
    l.c += l.a * c.x + l.b * c.y;
    ld D = r * r * (l.a * l.a + l.b * l.b) - l.c * l.c;
    if (D < -EPS) return;
    D = sqrt(fabs(D));
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
    if (c1 == c2) return;
    Line l;
    l.a = 2 * (c1.x - c2.x);
    l.b = 2 * (c1.y - c2.y);
    l.c = c2.x * c2.x - c1.x * c1.x + c2.y * c2.y - c1.y * c1.y + r1 * r1 - r2 * r2;
    crossCircleLine(c1, r1, l, v);
}

ld dist2(const Point& p1, const Point& p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool insideCircle(const Point& p, const Point& c, ld r)
{
    return dist2(p, c) < r * r + EPS;
}

bool can(ld R)
{
    vp.clear();

    forn(i, n) vp.pb(c[i]);

    forn(i, n)
    {
        forn(j, i)
        {
            crossCircles(c[i], R - r[i], c[j], R - r[j], vp);
        }
    }

    vector<ll> vm(vp.size());

    forv(i, vp)
    {
        ll mask = 0;

        forn(j, n)
        {
            if (insideCircle(vp[i], c[j], R - r[j]))
            {
                mask |= (1LL << j);
            }
        }

        vm[i] = mask;
    } 

    ll amask = (1LL << n) - 1;

    sort(all(vm));

    vm.erase(unique(all(vm)), vm.end());

    forv(i, vm)
    {
        ll mask = amask ^ vm[i];

        int k = int(lower_bound(all(vm), mask) - vm.begin());

        for (int j = k; j < vm.size(); j++)
        {
            if ((mask & vm[j]) == mask)
            {
                return true;
            }
        }
    }

    return false;   
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);

    cin >> n;

    ld maxR = 0;

    forn(i, n)
    {
        cin >> c[i].x >> c[i].y >> r[i];
        maxR = max(maxR, r[i]);
    }

    cout.precision(8);
    cout << fixed;

    if (n == 1)
    {
        cout << r[0] << endl;
        return;
    }
    
    ld lf = maxR, rg = 1e4;

    forn(it, 60)
    {
        ld mid = (lf + rg) / 2;

        if (can(mid)) rg = mid; else lf = mid;
    }

    cout << rg << endl;
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
            

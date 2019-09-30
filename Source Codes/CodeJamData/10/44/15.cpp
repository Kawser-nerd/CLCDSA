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
    Point() {};
    Point(ld x, ld y): x(x), y(y) {};
};

#define MMAX 20
#define EPS 1e-9
#define PI 3.14159265358979323846264338

int n, m;
Point p1, p2;
Point q[MMAX];

ld dist(Point p1, Point p2)
{
    return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

ld calc(Point c)
{
    ld R = dist(p1, c);
    ld r = dist(p2, c);

    ld d = dist(p1, p2);

    if (d + EPS > r + R) return 0.0;
    if (d + r < R + EPS) return PI * r * r;
    if (d + R < r + EPS) return PI * R * R;

    return r * r * acosl((d*d + r*r - R*R) / (2*d*r)) + R * R * acosl((d*d - r*r + R*R) / (2*d*R)) -
            0.5 * sqrtl((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)); 
}

void solve(int tc)
{
    printf("Case #%d:", tc);
    cin >> n >> m;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;

    forn(i, m) cin >> q[i].x >> q[i].y;

    forn(i, m)
    {
        printf(" %.8lf", (double)calc(q[i]));    
    }
    printf("\n");
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);
    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    return 0;
}
            

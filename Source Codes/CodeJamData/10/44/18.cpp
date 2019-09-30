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

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 15
#define EPS 1e-8

#define pi 3.14159265358979323846

struct Point
{
    ld x, y;
};

Point p1, p2;
Point q;

ld dist(Point& p1, Point& p2)
{
    return sqrt(fabsl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

ld acos1(ld x)
{
    if (x < -1) x = -1;
    if (x > 1) x = 1;
    return acosl(x);
}
void solve1()
{
    ld r1 = dist(p1, q);
    ld r2 = dist(p2, q);
    ld d = dist(p1, p2);

    if (d + r1 < r2 + EPS)
    {
        cout << " " << pi * r1 * r1;
        return;
    }

    if (d + r2 < r1 + EPS)
    {
        cout << " " << pi * r2 * r2;
        return;
    }

    ld alpha1 = 2 * acos1((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    ld alpha2 = 2 * acos1((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));

    ld ans = 0.5 * r1 * r1 * (alpha1 - sinl(alpha1)) + 0.5 * r2 * r2 * (alpha2 - sinl(alpha2)) ;

    cout << " " << ans; 
    
}
void solve(int test)
{
    printf("Case #%d:", test);

    int n, m;
    cin >> n >> m;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    forn(i, m)
    {
        cin >> q.x >> q.y;
        solve1();
    }

    printf("\n");
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    cout << fixed;
    cout.precision(15);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
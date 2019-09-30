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

#define NMAX 105

int n;
struct Point
{
    int x, y;
};

inline bool operator<(const Point& p1, const Point& p2)
{
    return p1.x > p2.x;
}

Point p[NMAX];
bool g[NMAX][NMAX];

bool can1()
{
    forn(i, n)
    {
        forn(j, i)
        {
            if (g[i][j]) return false;
        }
    }
    return true;
}

int color[NMAX];
bool ok;

void dfs(int v, int c)
{
    if (!ok) return;
    color[v] = c;

    forn(i, n)
    {
        if (g[v][i])
        {
            if (color[i] == c) 
            {
                ok = false;
                return;
            }
            if (color[i] == 0) dfs(i, -c);
        }
    }
}
bool can2()
{
    memset(color, 0, sizeof(color));
    ok = true;
    forn(i, n)
    {
        if (color[i] == 0) dfs(i, 1);

    }    
    return ok;
}

set<ll> s[2];

int getbit(ll mask, int i)
{
    return (mask >> (i << 1)) & 3;
}

void putbit(ll& mask, int i, int c)
{
    int c1 = getbit(mask, i);
    mask ^= ((c ^ c1) << (i << 1));
}
bool can(ll mask1, int c, Point& p, ll& mask2)
{
    if (getbit(mask1, p.y) == c || (p.y > 0 && getbit(mask1, p.y-1) == c) || (p.y < 15 && getbit(mask1, p.y+1) == c)) return false;
    mask2 = mask1;
    putbit(mask2, p.y, c);
    return true;
}
bool can3()
{
    s[0].clear();
    s[0].insert(0);

    forn(i, n)
    {
        int i1 = i & 1;
        int i2 = (i + 1) & 1;
        s[i2].clear();
        vector<ll> v(all(s[i1]));

        if (v.empty()) return false;

        forv(j, v)
        {
            for1(c, 3)
            {
                ll tmp;
                if (can(v[j], c, p[i], tmp))
                {
                    s[i2].insert(tmp);
                }
            }
        }
    }    

    return !s[n & 1].empty();
}

void solve(int test)
{
    cerr << test << endl;
    printf("Case #%d: ", test);
    scanf("%d", &n);
 //   if (n <= 20) printf("%d\n", n);
    forn(i, n)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
//        if (n <= 20)    printf("%d %d\n", p[i].x, p[i].y);
        p[i].y--;
    }
    memset(g, 0, sizeof(g));
    sort(p, p + n);
    forn(i, n)
    {
        for (int j = i-1; j >=0; j--)
        {
            if (p[j].y == p[i].y)
            {
                g[i][j] = g[j][i] = true;
                break;
            }
        }

        for (int j = i-1; j >=0; j--)
        {
            if (p[j].y == p[i].y + 1)
            {
                g[i][j] = g[j][i] = true;
                break;
            }
        }
        for (int j = i-1; j >=0; j--)
        {
            if (p[j].y == p[i].y - 1)
            {
                g[i][j] = g[j][i] = true;
                break;
            }
        }
    }    

    if (can1())
    {
        printf("1\n");
        return;
    }

    if (can2())
    {
        printf("2\n");
        return;
    }

    if (can3())
    {
        printf("3\n");
        return;
    }

    printf("4\n");

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}
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

#define MAGIC 100

struct Point
{
    ld x, y;
};

ld find_bin(ld need, vector<Point>& l, vector<Point>& u)
{
    ld L = 0, R = l.back().x;

    forn(it, MAGIC)
    {
        ld x = (L + R) / 2, y;

        ld sq = 0; 
        forn(i, (int)l.size() - 1)
        {
            if (l[i + 1].x < x)
            {
                sq -= (l[i + 1].x - l[i].x) * (l[i + 1].y + l[i].y);   
            }
            else
            {
                y = l[i].y + (x - l[i].x) / (l[i + 1].x - l[i].x) * (l[i + 1].y - l[i].y);
                sq -= (x - l[i].x) * (y + l[i].y);
                break;
            }
        }

        forn(i, (int)u.size() - 1)
        {
            if (u[i + 1].x < x)
            {
                sq += (u[i + 1].x - u[i].x) * (u[i + 1].y + u[i].y);   
            }
            else
            {
                y = u[i].y + (x - u[i].x) / (u[i + 1].x - u[i].x) * (u[i + 1].y - u[i].y);
                sq += (x - u[i].x) * (y + u[i].y);
                break;
            }
        }

        if (sq < need) L = x; else R = x;
    }

    return (L + R) / 2;
}

void solve(int test)
{
    printf("Case #%d:\n", test);

    ld W; 
    int L, U;
    cin >> W >> L >> U;
    int G; cin >> G;
    
    vector<Point> l(L);
    vector<Point> u(U);

    forv(i, l)
    {
        cin >> l[i].x >> l[i].y;
    }
    forv(i, u)
    {
        cin >> u[i].x >> u[i].y;
    }

    ld sq = 0;
    forn(i, U - 1)
    {
        sq += (u[i + 1].x - u[i].x) * (u[i + 1].y + u[i].y);    
    }
    forn(i, L - 1)
    {
        sq -= (l[i + 1].x - l[i].x) * (l[i + 1].y + l[i].y);
    }

    sq /= G;

    for1(i, G - 1)
    {
        ld need = sq * i;
        cout << find_bin(need, l, u) << endl;        
    }
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    cout << fixed;
    cout.precision(12);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
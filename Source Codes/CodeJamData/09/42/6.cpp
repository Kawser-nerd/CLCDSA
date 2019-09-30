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

typedef long double ld;
typedef pair<int, int> pii;

#define NMAX 52
#define INF 1000000

int n, m, f;
string a[NMAX];
int d[NMAX][NMAX][NMAX][NMAX];
bool used[NMAX][NMAX][NMAX][NMAX];

struct State
{
    int x, y, l, r;
};

queue<State> q;

void update(int x, int y, int l, int r, int xx, int yy, int ll, int rr, int add)
{
    if (d[xx][yy][ll][rr] > d[x][y][l][r] + add)
    {
        d[xx][yy][ll][rr] = d[x][y][l][r] + add;
        if (!used[xx][yy][ll][rr])
        {
            used[xx][yy][ll][rr] = true;
            State st = {xx, yy, ll, rr};
            q.push(st);
        }
    }
}

void solve(int tc)
{   
    cerr << tc << endl;
    printf("Case #%d: ", tc);

    cin >> n >> m >> f;

    forn(i, n) cin >> a[i];
    forn(i, n)
    {
        forn(j, m)
        {
            forn(i1, m + 1)
            {
                forn(j1, m + 1)
                {
                    d[i][j][i1][j1] = INF;
                }
            }
        }
    }

    memset(used, 0, sizeof(used));

    d[0][0][0][0] = 0;
    used[0][0][0][0] = true;

    State st = {0, 0, 0, 0};
    q.push(st);

    while (!q.empty())
    {
        State u = q.front();
        q.pop();
        int x = u.x;
        int y = u.y;
        int l = u.l;
        int r = u.r;

        if (x == n - 1) continue;

        used[x][y][l][r] = false;

        int ly = y - l;
        int ry = y + r;

        while (ly - 1 >= 0 && a[x][ly - 1] == '.') --ly;
        while (ry + 1 < m && a[x][ry + 1] == '.') ++ry;

        int lh = y;

        while (lh >= ly && a[x + 1][lh] != '.') --lh;

        int rh = y;

        while (rh <= ry && a[x + 1][rh] != '.') ++rh;

        //go left and fall

        if (lh >= ly)
        {
            int xx = x;
            int yy = lh;

            while (xx + 1 < n && a[xx + 1][yy] == '.') ++xx;

            if (xx - x <= f) update(x, y, l, r, xx, yy, 0, 0, 0);
        } 

        //go right and fall

        if (rh <= ry)
        {
            int xx = x;
            int yy = rh;

            while (xx + 1 < n && a[xx + 1][yy] == '.') ++xx;

            if (xx - x <= f) update(x, y, l, r, xx, yy, 0, 0, 0);
        } 

        //dig some holes to the right
        
        for (int i = lh + 2; i < rh; i++)
        {
            for (int j = i; j < rh; j++)
            {
                int xx = x + 1;
                int yy = i;

                while (xx + 1 < n && a[xx + 1][yy] == '.') ++xx;

                if (xx - x <= f)
                {
                    if (xx == x + 1)
                    {
                        update(x, y, l, r, xx, yy, 0, j - i, j - i + 1);
                    }
                    else
                    {
                        update(x, y, l, r, xx, yy, 0, 0, j - i + 1);
                    }
                }
            }
        }
       

        //dig some holes to the left      
        for (int i = rh - 2; i > lh; i--)
        {
            for (int j = i; j > lh; j--)
            {
                int xx = x + 1;
                int yy = i;

                while (xx + 1 < n && a[xx + 1][yy] == '.') ++xx;

                if (xx - x <= f) 
                {
                    if (xx == x + 1)
                    {
                        update(x, y, l, r, xx, yy, i - j, 0, i - j + 1);
                    }
                    else
                    {
                        update(x, y, l, r, xx, yy, 0, 0, i - j + 1);
                    }
                }
            }
        }
        
    }


    int ans = INF;

    forn(i, m)
    {
        forn(l, m + 1)
        {
            forn(r, m + 1)
            {
                ans = min(ans, d[n - 1][i][l][r]);
            }
        }
    }

    if (ans == INF) printf("No\n"); else printf("Yes %d\n", ans);
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
            

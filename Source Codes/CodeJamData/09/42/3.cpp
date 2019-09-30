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

#define NMAX 55
#define INF 1000000009

int n, m, f;

int a[NMAX][NMAX];

struct Pos
{
    int x, l, r;
    int i1, i2;
};

Pos down(int x, int y, bool fst = false)
{
    Pos ret;
    forn(i, f + 1)
    {
        if ((i > 0 || fst) && a[x+1][y] == 1)
        {
            ret.x = x;
            break;           
        }
        if (i == f)
        {
            ret.x = -1;
            return ret;            
        }
        x++;           
    }
    ret.l = ret.r = y;
    while (ret.l > 0 && a[ret.x][ret.l-1] == 0 && a[ret.x+1][ret.l-1] == 1) ret.l--;
    while (ret.r < m-1 && a[ret.x][ret.r+1] == 0 && a[ret.x+1][ret.r+1] == 1) ret.r++;

    if (ret.l == 0 || a[ret.x][ret.l-1] == 1) ret.i1 = 1; else ret.i1 = 0;
    if (ret.r == m-1 || a[ret.x][ret.r+1] == 1) ret.i2 = 1; else ret.i2 = 0;

    return ret;
} 

int d[NMAX][NMAX][NMAX][2][2];

void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d %d %d\n", &n, &m, &f);

    forn(i, n)
    {
        forn(j, m)
        {
            char c; scanf("%c", &c);
            if (c == '.') a[i][j] = 0; else a[i][j] = 1;
        }
        scanf("\n");
    }

    forn(j, m) a[n][j] = 1;

    Pos start;
    start = down(0, 0, true);

    if (start.x == -1) 
    {
        cout << "No\n";
        return;
    }

    forn(i, NMAX) forn(j, NMAX) forn(k, NMAX) forn(i1, 2) forn(i2, 2) d[i][j][k][i1][i2] = INF;
    d[start.x][start.l][start.r][start.i1][start.i2] = 0;

    Pos u;
    forn(x, n - 1)
    {
        forn(l, m)
        {
            for (int r = l; r < m; r++)
            {
                forn(i1, 2)
                {
                    forn(i2, 2)
                    {
                        if (d[x][l][r][i1][i2] == INF) continue;

                       // printf("%d %d %d %d %d: %d\n", x, l, r, i1, i2, d[x][l][r][i1][i2]); 

                        if (i1 == 0) //just go left
                        {
                            u = down(x, l-1);
                            if (u.x != -1)
                            {
                                d[u.x][u.l][u.r][u.i1][u.i2] = min(d[u.x][u.l][u.r][u.i1][u.i2], d[x][l][r][i1][i2]);
                            }
                        }

                        if (i2 == 0) //just go right
                        {
                            u = down(x, r + 1);
                            if (u.x != -1) 
                            {
                                d[u.x][u.l][u.r][u.i1][u.i2] = min(d[u.x][u.l][u.r][u.i1][u.i2], d[x][l][r][i1][i2]);
                            }
                        }

                        //dig from left to right

                        for (int l1 = l; l1 < r; l1++)
                        {
                            for (int r1 = l1; r1 < r; r1++)
                            {
                                u = down(x, r1);
                                if (u.x != -1) 
                                {
                                    if (u.x == x + 1)
                                    {
                                        assert(u.i2 == 1);
                                        while (u.l > 0 && a[u.x+1][u.l-1] == 1 && (a[u.x][u.l-1] == 0 || u.l -1 >= l1)) u.l--;
                                        if (u.l == 0 || (a[u.x][u.l-1] == 1 && u.l - 1 < l1)) u.i1 = 1; else u.i1 = 0;
                                    }
                                    d[u.x][u.l][u.r][u.i1][u.i2] = min(d[u.x][u.l][u.r][u.i1][u.i2], d[x][l][r][i1][i2] + r1 - l1 + 1);
                                }
                            }
                        }

                        //dig from right to left

                        for (int l1 = l + 1; l1 <= r; l1++)
                        {
                            for (int r1 = l1; r1 <= r; r1++)
                            {
                                u = down(x, l1);
                                if (u.x != -1) 
                                {
                                    if (u.x == x + 1)
                                    {
                                        assert(u.i1 == 1);
                                        while (u.r < m-1 && a[u.x+1][u.r+1] == 1 && (a[u.x][u.r+1] == 0 || u.r +1 <= r1)) u.r++;
                                        if (u.r == 0 || (a[u.x][u.r+1] == 1 && u.r + 1 > r1)) u.i2 = 1; else u.i2 = 0;
                                    }
                                    d[u.x][u.l][u.r][u.i1][u.i2] = min(d[u.x][u.l][u.r][u.i1][u.i2], d[x][l][r][i1][i2] + r1 - l1 + 1);
                                }
                            }
                        }
                    }
                }
            }
        }        
    }

    int ans = INF;
    for (int l = 0; l < m; l++)
    {
        for (int r = l; r < m; r++)
        {
            forn(i1, 2)
            {
                forn(i2, 2)
                {
                    ans = min(ans, d[n-1][l][r][i1][i2]);
                }
            }
        }
    }
    if (ans == INF) cout << "No\n";
    else cout << "Yes " << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}
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
#define KMAX 30

int n, k;
int p[NMAX][KMAX];
bool g[NMAX][NMAX];
bool used[NMAX];
int mm[NMAX];

bool khun(int v)
{
    if (used[v]) return false;
    used[v] = true;

    forn(i, n)
    {
        if (!g[v][i]) continue;
        if (mm[i] == -1 || khun(mm[i]))
        {
            mm[i] = v;
            return true;
        }
    }

    return false;
}
void solve(int test)
{    
    printf("Case #%d: ", test);
    scanf("%d %d", &n, &k);

    forn(i, n)
    {
        forn(j, k)
        {
            scanf("%d", &p[i][j]);
        }
    }

    memset(g, 0, sizeof(g));
    forn(i, n)
    {
        forn(j, n)
        {
            bool f = true;
            forn(c, k)
            {
                if (p[i][c] >= p[j][c])
                {
                    f = false;
                    break;
                }
            }
            if (f) g[i][j] = true;
        }
    }

    memset(mm, 255, sizeof(mm));

    forn(i, n)
    {
        memset(used, 0, sizeof(used));
        khun(i);
    }

    int ans = 0;
    forn(i, n)
    {
        if (mm[i] == -1) ans++;
    }
    cout << ans << endl;
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
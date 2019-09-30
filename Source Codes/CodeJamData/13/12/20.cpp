#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

#define NMAX 20

int d[NMAX][NMAX];
int n, e, r;
int v[NMAX];

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    cin >> e >> r >> n;
    forn(i, n) cin >> v[i];
    forn(i, n + 1) forn(j, e + 1) d[i][j] = -1;

    d[0][e] = 0;

    forn(i, n)
    {
        forn(j, e + 1)
        {
            if (d[i][j] < 0) continue;

            forn(k, j + 1)
            {
                int t = min(e, j - k + r);
                d[i + 1][t] = max(d[i + 1][t], d[i][j] + v[i] * k);
            }
        }
    }

    int ans = -1;
    forn(i, e + 1) ans = max(ans, d[n][i]);
    cout << ans << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}

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

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    ll r, t;
    cin >> r >> t;
    ll lf = 0, rg = min(t / (2 * r + 1), 2500000000ll);

    while (rg - lf > 2)
    {
        ll n = (lf + rg) / 2;

        ll s = (2 * r + 1 + (n - 1) * 2) * n;

        if (s <= t) lf = n; else rg = n - 1;
    }

    for (ll n = rg; n >= lf; n--)
    {
        ll s = (2 * r + 1 + (n - 1) * 2) * n;
        if (s <= t) 
        {
            cout << n << endl;
            return;
        }
    }
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

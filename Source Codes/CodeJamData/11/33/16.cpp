#pragma comment(linker, "/STACK:256000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define sort_unique(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<ll> vl;

struct Point
{
    int x, y;
};

ll gcd(ll a, ll b)
{
    if (a == 0) return b;
    else return gcd(b % a, a);
}

int digits(ll x)
{
    int ret = 0;
    while (x > 0)
    {
        ret++;
        x /= 10;
    }
    return ret;
}

ll lcm(ll a, ll b)
{
    ll d = gcd(a, b);
    if (a > 0) a /= d;
    else b /= d;
    if (digits(a) + digits(b) - 1 > 16) return -1;
    return a * b;
}

int main()
{
 //   freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    forn(it, tc)
    {
        int N; cin >> N;
        ll L, H;cin >> L >> H;
        vl f(N);
        forn(i, N) cin >> f[i];
        sort(all(f));
        if (f[0] != 1)
        {
            f.push_back(1);
            sort(all(f));
            ++N;
        }
        vl g(N + 1);
        g[N] = 0;
        for(int i = N - 1; i >= 0; --i)
        {
            g[i] = gcd(f[i], g[i + 1]);
        }
        ll ans = ll(1e18);
        ll lm = 1;
        forn(i, N)
        {
            lm = lcm(lm, f[i]);
            if (lm == -1) break;
            if (g[i + 1] % lm != 0) continue;
            ll dv = g[i + 1] / lm;
            if (dv == 0) 
            {
                ll x = (L + lm - 1) / lm;
                x *= lm;
                if (L <= x && x <= H)
                {
                    ans = min(ans, x);
                }
            }
            ll l = (L + lm - 1) / lm;
            ll r = H / lm;
            for(ll x = 1; x * x <= dv; ++x)
            {
                if (dv % x == 0) {
                    if (l <= x && x <= r) {
                        ans = min(ans, x * lm);
                    }
                    ll y = dv / x;
                    if (l <= y && y <= r)
                    {
                        ans = min(ans, y * lm);
                    }
                }
            }    
        }
        if (ans > H) {
            cout << "Case #" << it + 1 << ": NO" << endl;
        }
        else
        {
            cout << "Case #" << it + 1 << ": " << ans << endl;
        }
    }
    return 0;
}

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

int n, m, k, r;
vector< vector<int> > a;
vector<int> cur;
vector< map<ll, int> > cnt;
vector<ll> ways;

int total;

vector<ll> fact;

ll calc_ways(vector<int> p)
{
    sort(all(p));
    ll ret = fact[p.size()];
    int l = 0;
    while (l < p.size())
    {
        int r = l;
        while (r < p.size() && p[l] == p[r]) r++;
        ret /= fact[r - l];
        l = r;
    }
    return ret;
}

void rec(int p)
{
    if (p == n)
    {
        total++;
        
        a.pb(cur);
        ways.pb(calc_ways(cur));
        cnt.pb(map<ll, int>());
        forn(mask, (1 << n))
        {
            ll prod = 1;
            forn(i, n) if (mask & (1 << i)) prod *= cur[i];
            cnt[cnt.size()-1][prod]++;
        }
        
        return;
    }

    int last = 2;
    if (p) last = cur[p - 1];

    for (int i = last; i <= m; i++)
    {
        cur[p] = i;
        rec(p + 1);
    }
}

int random(int n)
{
    int r = (rand() << 15) ^ rand();
    return abs(r) % n;
}

int random(int l, int r)
{
    return l + random(r - l + 1);
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d:\n", tc);
    cin >> r >> n >> m >> k;

    fact = vector<ll>(n + 1, 0);
    fact[0] = 1;
    for1(i, n) fact[i] = fact[i - 1] * i;

    cur = vector<int>(n, 0);
    a.clear();
    rec(0);

    int ok = 0;

    forn(it, r)
    {
        if ((it + 1) % 100 == 0)
        {
            cerr << it + 1 << " " << clock() / 1000 << endl;
        }
        vector<ll> b(k);
        forn(i, k) cin >> b[i];

        /*
        forn(i, n)
        {
            cur[i] = random(2, m);
        }

        sort(all(cur));

        forn(i, k)
        {
            int mask = random(0, (1 << n) - 1);

            ll prod = 1;
            forn(j, n) if (mask & (1 << j)) prod *= cur[j];

            b[i] = prod;
        }
        */

        sort(all(b));
        reverse(all(b));
               

        long double maxp = 0;
        int best = 0;

        forv(i, a)
        {
            long double curp = 1.0;
            forn(j, k)
            {
                map<ll, int>::iterator it = cnt[i].find(b[j]);
                if (it == cnt[i].end())
                {
                    curp = 0;
                    break;
                }
                else curp *= it->second;
            }

            curp *= (long double)ways[i] / a.size();

            if (curp > maxp)
            {
                maxp = curp;
                best = i;
            }
        }

        /*
        int i = 0;
        while (a[i] != cur) i++;

        long double realp = 1.0;
            forn(j, k)
            {
                map<ll, int>::iterator it = cnt[i].find(b[j]);
                if (it == cnt[i].end())
                {
                    realp = 0;
                    break;
                }
                else realp *= it->second;
            }

        
        cout.precision(10);
        cout << fixed << maxp << endl;
        cout << fixed << realp << endl;

        if (cur == a[best]) 
        {
            ok++;
            cout << "ok\n";
        } else cout << "no\n";
        */
        

        forn(i, n) cout << a[best][i];
        cout << endl;
    }

    //cerr << ok * 100.0 / r << "% of success." << endl;
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

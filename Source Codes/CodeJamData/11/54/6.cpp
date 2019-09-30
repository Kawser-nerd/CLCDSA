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

ll toLL(string s)
{
    ll r = 0;
    forv(i, s)
    {
        r = r * 2 + int(s[i] - '0');
    }
    return r;
}

bool sq(ll n)
{
    ll L = 0;
    ll R = ll(floor(2 * sqrtl(ld(n))));

    while (R - L > 2)
    {   
        ll mid = (R + L) / 2;
        if (mid * mid == n) return true;
        if (mid * mid < n) L = mid; else R = mid;
    }

    for (ll i = L; i <= R; i++)
    {
        if (i * i == n) return true;
    }

    return false;
}
void solve(int test)
{
    printf("Case #%d: ", test);
    cerr << test << endl;

    string s;
    cin >> s;

    vector<int> q;

    forv(i, s) 
    {
        if (s[i] == '?')
        {
            q.pb(i);
        }
    }

    forn(mask, (1 << (int)q.size()))
    {
        forv(i, q)
        {
            if (mask & (1 << i)) s[q[i]] = '1'; else s[q[i]] = '0';
        }

        ll x = toLL(s);
        if (sq(x))
        {
            cout << s << endl;
            return;
        }
    }

    assert(false);
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
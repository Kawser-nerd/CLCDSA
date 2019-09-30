#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

const int mod = 1000000007;

inline ll ha (ll n)
{
    n %= mod;
    return (n * (n + 1) / 2) % mod;
}

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector <ll> a;
    int rev;
    int x;
    ll y;        
    
    for (int b2 = 1; b2 <= 1000000; b2 *= 10)
    {
        for (int i = b2 / 10; i < b2; ++i)
        {
            x = i;
            rev = 0;
            ll dec = 1;
            while (x)
            {
                rev = rev * 10 + x % 10; 
                x /= 10;
                dec = dec * 10;
            }
            y = i * dec + rev;
            a.pb (y);
        }
        for (int i = b2 / 10; i < b2; ++i)
        {
            x = i;
            rev = 0;
            ll dec = 1;
            while (x)
            {
                rev = rev * 10 + x % 10; 
                x /= 10;
                dec = dec * 10;
            }                
            REP (j, 10)
            {
                y = i * dec * 10 + j * dec + rev;
                a.pb (y);
            }
        }
    }
    
    int test;
    cin >> test;
    FOR (ntest, 1, test+1)
    {
        cout << "Case #" << ntest << ": ";
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        
        int q, w;
        q = lower_bound (ALL (a), l) - a.begin();
        w = lower_bound (ALL (a), r + 1) - a.begin();        
        if (q >= w)
        {
            res = ha (r - l + 1);
        } else
        {
            res = ha (a[q] - l);
            res += ha (r - a[w-1]);
            res %= mod;
            ll h[2] = {0, 0};
            REP (i, w - q - 1)
            {
                h[i&1] += a[q+i+1] - a[q+i];
                h[i&1] %= mod;
            }
            h[(w-q-1)&1] += r - a[w-1] + 1;
            h[(w-q-1)&1] %= mod;
            REP (i, w-q-1)
            {
                res += ha (a[q+i+1]-a[q+i]-1);
                res %= mod;
            }
            REP (i, w-q)
            {
                ll much;
                if (!i)
                    much = a[q+0] - l + 1;
                else
                    much = a[q+i] - a[q+i-1];
                much %= mod;
                res += much * h[~i&1];
                res %= mod;
                
                if (i != w-q - 1)
                {
                    h[i&1] -= a[q+i+1] - a[q+i];
                    h[i&1] %= mod;
                    h[i&1] += mod;
                    h[i&1] %= mod;
                }
            }            
        }
        cout << res << endl;        
    }    
	return 0;
}

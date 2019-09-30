#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

const ll mod = 1000000007;
const int N = 10010;
ll fact[N], invf[N];

ll add(ll x, ll y){
    return (x+y)%mod;
}

ll mul(ll x, ll y){
    return (x%mod)*(y%mod)%mod;
}

ll powll(ll x, ll y){
    ll res = 1LL;
    while(y){
        if (y & 1LL)
            res *= x;
        res %= mod;
        x = (x*x) % mod;
        y >>= 1LL;
    }
    return res;
}

ll divll(ll x, ll y){
    return (x * powll(y,mod-2)) % mod;
}

ll nPr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(fact[n], invf[n-r]);
}

ll nCr(ll n, ll r){
    if (n < r || r < 0) return 0;
    return mul(mul(fact[n], invf[r]), invf[n-r]);
}

VI Centroid(VVI &graph){
    int n = graph.size();
    VI ret, sz(n);
    function<void (int, int)> dfs = [&](int now, int past){
        sz[now] = 1;
        bool is_centroid = true;
        for (int next : graph[now]){
            if (next == past) continue;
            dfs(next, now);
            sz[now] += sz[next];
            if (sz[next] > n / 2) is_centroid = false;
        }
        if (n - sz[now] > n / 2) is_centroid = false;
        if (is_centroid) ret.push_back(now);
    };
    dfs(0, -1);
    return ret;
}

int dfs(int now, int past, VVI &e){
    int ret = 1;
    for (int next : e[now]){
        if (next == past) continue;
        ret += dfs(next, now, e);
    }
    return ret;
}

ll dp[5010][5010];

int main() {
    int n;
    cin >> n;
    VVI e(n);
    REP(i,n-1){
        int u = in() - 1, v = in() - 1;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    fact[0] = invf[0] = 1;
    FOR(i,1,N-1){
        fact[i] = (fact[i-1] * i) % mod;
        invf[i] = divll(invf[i-1], i);
    }

    VI cs = Centroid(e);

    if (cs.size() == 2){
        ll ans = fact[n / 2];
        ans = (ans * ans) % mod;
        cout << ans << endl;
        return 0;
    }

    int c = cs[0];
    VI a;
    for (int v : e[c]){
        a.push_back(dfs(v, c, e));
    }
    int k = a.size();

    dp[0][0] = 1;
    REP(i,k){
        REP(j,n){
            REP(s,a[i]+1){
                ll tmp = dp[i][j];
                tmp = (tmp * fact[s]) % mod;
                tmp = (tmp * nCr(a[i], s)) % mod;
                tmp = (tmp * nCr(a[i], s)) % mod;
                dp[i + 1][j + s] = (dp[i + 1][j + s] + tmp) % mod;
            }
        }
    }

    ll ans = 0;
    REP(i,n){
        ll tmp = (fact[n - i] * dp[k][i]) % mod;
        if (i % 2 == 0) ans = (ans + tmp) % mod;
        else ans = (ans - tmp + mod) % mod;
    }
    cout << ans << endl;

    return 0;
}
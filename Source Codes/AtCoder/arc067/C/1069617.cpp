?#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <cstring>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

const ll MOD = 1000000007;
ll Cb[1010][1010]; // nCk?????
ll MI[1010]; // ModInverse?????

// Calculates x raised to the y-th power modulo MOD
// x?y?????????????????????
ll modPow(ll x, ll y)
{
    ll r=1, a=x;
    while (y > 0) {
        if ( (y&1)==1 ) {
            r = (r * a) % MOD;
        }
        a = (a * a) % MOD;
        y /= 2;
    }
    
    return r;
}
// Modular multiplicative inverse through Fermat's little theorem:
// ???????????, a^-1 ? a^(p-2) (mod p) ??????????
// ????p?????????????
ll modInverse(ll x)
{
    return modPow(x, MOD-2);
}

// Modular division x / y, find modular multiplicative inverse of y
// and multiply by x.
ll modDivision(ll p, ll q)
{
    return (p * MI[q]) % MOD;
}
//
//// Binomial coifficient C(n,k) in O(k) time.
//ll choose(ll n, int k)
//{
//    if (k > n) {
//        return 0;
//    }
//    ll p = 1, q = 1;
//    for (int i=1; i<=k; i++) {
//        q = ( q * i) % MOD;
//        p = ( p * (n - i + 1) ) % MOD;
//    }
//    return modDivision(p, q);
//}

ll N, A, B, C, D;
// ll ans = 0;
//map<int, int> table;

//ll count() {
//    //printf("table:\n");
//    //for (auto kv : table) {
//    //    cout << kv.first << ": " << kv.second << endl;
//    //}
//    //cout << endl;
//
//    ll ans = 1;
//    ll n = N;
//    for(auto& kv: table) {
//        REP(i, kv.second) {
//            ans *= choose(n, kv.first);
//            n -= kv.first;
//        }
//        FOR(i, 2, kv.second + 1) {
//            ans = modDivision(ans, i);
//        }
//    }
//    return ans;
//}

//map<tuple<int, int, int>, ll> cache2;
//ll count2(int n, int group_size, int group_num) {
//    if (cache2.count(mt(n, group_size, group_num))) {
//        return cache2[mt(n, group_size, group_num)];
//    }
//
//    ll ans = 1;
//    REP(i, group_num) {
//        ans *= Cb[n][group_size];
//        ans %= MOD;
//        n -= group_size;
//    }
//    FOR(i, 2, group_num + 1) {
//        ans = modDivision(ans, i);
//    }
//    cache2[mt(n, group_size, group_num)] = ans;
//    return ans;
//}


ll cache[1010][1010];
// a???????????n????????????
ll dfs(ll n, ll a) {
    if (cache[n][a] != -1) return cache[n][a];
    if (n == 0) return 1; // ?
    if (a < A) return 0;
    //printf("n, a = %d, %d\n", n, a);

    ll ans = 0;
    if (a >= A + 1) {
        ans += dfs(n, a - 1);
        ans %= MOD;
    }

    ll val = 1;
    ll remain = n;
    FOR(i, 1, D + 1) {
        ll x = i * a;
        val *= Cb[remain][a];
        val %= MOD;
        val = modDivision(val, i);
        remain -= a;

        if (x > n) break;
        if (i < C) continue;

        ans += val * dfs(n - x, a - 1) % MOD;
        ans %= MOD;
    }

    cache[n][a] = ans;
    //printf("cache[%d][%d] = %d\n", n, a, ans);
    assert(ans >= 0LL);
    return ans;
}
    
int main(void)
{
    cin.sync_with_stdio(false);
    cin >> N >> A >> B >> C >> D;

    memset(cache, -1, sizeof(cache));

    // ????????
    Cb[0][0] = 1;
    FOR(i, 1, N + 1) {
        Cb[i][0] = 1;
        FOR(j, 1, N + 1) {
            Cb[i][j] = (Cb[i - 1][j - 1] + Cb[i - 1][j]) % MOD;
        }
    }
    FOR(i, 1, N + 1) {
        MI[i] = modInverse(i);
    }

    ll ans = dfs(N, B);
    cout << ans << endl;

    return 0;
}
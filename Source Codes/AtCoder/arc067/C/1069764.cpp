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

class nCk {
private:
    ll m_mod;
    ll m_precompChooseMax = -1;
    ll m_precompModInverseMax = -1;
    vector<vector<ll>> m_chooseResult;
    vector<ll> m_modInverseResult;

public:
    // mod must be a prime number
    nCk(ll mod) : m_mod(mod) {}

    // x^y % m_mod
    ll modPow(ll x, ll y)
    {
        ll r = 1, a = x;
        while (y > 0) {
            if ((y&1) == 1) {
                r = (r * a) % m_mod;
            }
            a = (a * a) % m_mod;
            y /= 2;
        }
        return r;
    }

    // a^-1 ? a^(p-2) (mod p)   (p is prime)
    ll modInverse(ll x)
    {
        if (x <= m_precompModInverseMax) return m_modInverseResult[x];
        else return modPow(x, m_mod-2);
    }

    // Modular division x / y, find modular multiplicative inverse of y
    // and multiply by x.
    ll modDivision(ll p, ll q)
    {
        return (p * modInverse(q)) % m_mod;
    }

    // Binomial coifficient C(n,k) in O(k) time.
    ll choose(ll n, ll k)
    {
        if (max(n, k) <= m_precompChooseMax) {
            return m_chooseResult[n][k];
        }

        if (k > n) {
            return 0;
        }
        ll p = 1, q = 1;
        for (int i=1; i<=k; i++) {
            q = (q * i) % m_mod;
            p = (p * (n - i + 1)) % m_mod;
        }
        return modDivision(p, q);
    }

    // precompute nCk
    void precompChoose(ll n_max) {
        assert(n_max > 0);
        m_chooseResult.resize(n_max+1, vector<ll>(n_max+1));
        m_chooseResult[0][0] = 1;
        FOR(i, 1, n_max + 1) {
            m_chooseResult[i][0] = 1;
            FOR(j, 1, n_max + 1) {
                m_chooseResult[i][j]
                    = (m_chooseResult[i - 1][j - 1] + m_chooseResult[i - 1][j])
                    % m_mod;
            }
        }
        m_precompChooseMax = n_max;
    }
    // precompute modInverse
    void precompModInverse(ll n_max) {
        assert(n_max > 0);
        m_modInverseResult.resize(n_max + 1);
        FOR(i, 1, n_max + 1) {
            m_modInverseResult[i] = modInverse(i);
        }
        m_precompModInverseMax = n_max;
    }
};

const ll MOD = 1000000007;
nCk nck(MOD);

ll N, A, B, C, D;
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
        // val *= Cb[remain][a];
        val *= nck.choose(remain, a);
        val %= MOD;
        val = nck.modDivision(val, i);
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

    // ????????
    nck.precompChoose(1000);
    nck.precompModInverse(1000);

    memset(cache, -1, sizeof(cache));

    ll ans = dfs(N, B);
    cout << ans << endl;

    return 0;
}
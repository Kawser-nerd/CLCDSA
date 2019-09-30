#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

pair<vector<ll>, vector<ll>> prime_factor_decomp(ll n) {
    vector<ll> p, e;
    ll m = n;
    for (ll i = 2; i * i <= n; i++) {
        if (m % i != 0){
            continue;
        }
        int c = 0;
        while (m % i == 0){
            c++;
            m /= i;
        }
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return make_pair(p, e);
}

template<typename Int, Int MOD>
struct comb_util {
    int sz;
    vector<Int> mfact, minv_fact;
    comb_util(int N) : sz(N + 1), mfact(sz), minv_fact(sz) {
        mfact[0] = 1;
        for (int i = 1; i <= sz; i++) mfact[i] = mfact[i - 1] * i % MOD;
        minv_fact[sz] = inv(mfact[sz]);
        for (int i = sz - 1; i >= 0; i--) minv_fact[i] = minv_fact[i + 1] * (i + 1) % MOD;
    }

    // res = first * p^second
    pair<Int, Int> fact_willson(Int n) const {
        Int e = 0;
        if (n <= sz) return std::make_pair(mfact[n], 0);
        Int res;
        tie(res, e) = fact_willson(n / MOD);
        e += n / MOD;
        if ((n / MOD) % 2 != 0) res = MOD - res;
        return make_pair(res * mfact[n % MOD] % MOD, e);
    }

    // find n!
    Int fact(Int n) const { return mfact[n]; }

    // find n ** -1
    Int inv(Int n) const {
        return pow(n, MOD - 2);
    }

    // find n ** a
    Int pow(Int n, Int a) const {
        Int res = 1, exp = n;
        for(; a; a /= 2) {
            if (a & 1) res = res * exp % MOD;
            exp = exp * exp % MOD;
        }
        return res;
    }

    // find nPr
    Int perm(Int n, Int r) {
        if (r < 0 || n < r) return 0;
        else return mfact[n] * minv_fact[n - r] % MOD;
    }

    Int binom_lucus(Int n, Int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        assert(n <= sz);
        if (n >= MOD) return binom(n % MOD, r % MOD) * binom(n / MOD, r / MOD);
        else return r > n ? 0 : mfact[n] * minv_fact[n - r] * minv_fact[r];
    }

    // find nCr
    Int binom(Int n, Int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return mfact[n] * minv_fact[r] % MOD * minv_fact[n - r] % MOD;
    }

    // find nHr
    Int homo(Int n, Int r) const {
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : binom(n + r - 1, r);
    }
};
using comb = comb_util<long long, 1000000007>;

int main(){
    ll n, m;
    const ll div = 1000000000 + 7;
    comb cm(2000010);
    cin >> n >> m;
    pair<vector<ll>, vector<ll>> p = prime_factor_decomp(m);
    ll ans = 1;
    for (ll i=0; i<(ll)p.first.size(); ++i){
        ans *= cm.binom(p.second[i] + n - 1, p.second[i]);
        // cout << p.first[i] << " -> " << p.second[i] << endl;
        ans = ans % div;
    }
    cout << ans << endl;
    return 0;
}
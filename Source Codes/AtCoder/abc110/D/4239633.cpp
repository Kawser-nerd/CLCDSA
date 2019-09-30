#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;
using ll = long long;

ll N, M;

void input() {
    cin >> N >> M;
}

const ll MOD = 1e9+7;
ll mod(ll x) {
    return x % MOD;
}

ll pow_mod(ll x, ll p) {
    ll res = 1;
    ll u = x;
    while (p) {
        if (p & 1) {
            res = mod(res * u);
        }
        u = mod(u * u);
        p >>= 1;
    }
    return res;
}

ll div_mod(ll x) {
    return pow_mod(x, MOD - 2);
}


void solve() {
    vector<ll> fact(2e5);
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < fact.size(); i++) {
        fact[i] = mod(fact[i-1] * i);
    }
    vector<ll> ifact(fact.size());
    for (ll i = 0; i < ifact.size(); i++) {
        ifact[i] = div_mod(fact[i]);
    }
    
    auto comb_mod = [&fact, &ifact](ll a, ll b) {
        return mod(mod(fact[a] * ifact[b]) * ifact[a-b]);
    };
    
    ll ans = 1;
    ll m = M;
    for (ll n = 2; n <= M; n++) {
        ll count = 0;
        while (m % n == 0) {
            count++;
            m /= n;
        }
        if (count == 0)
            continue;
        ans = mod(ans * comb_mod(count + N - 1, count));
        
        if (m == 1)
            break;
    }
    cout << ans << endl;
}




int main() {
    input();
    solve();
    
    return 0;
}
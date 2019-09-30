#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll N;
vector<ll> A;
vector<ll> cA;
vector<ll> factorial;
const ll MOD = 1e9 + 7;

void input() {
    cin >> N;
    A.resize(N);
    for (auto& v : A) {
        cin >> v;
    }
}

ll modinv(ll x) {
    ll ans = 1;
    const ll p = MOD - 2;
    ll cpow = x;
    for (ll i = 0; p >> i; i++) {
        if ((p >> i) & 1)
            ans = (ans * cpow) % MOD;
        cpow = (cpow * cpow) % MOD;
    }
    ans = (ans + MOD) % MOD;
    return ans;
}

ll solve() {
    ll cmi[N + 1];
    cmi[0] = 0;
    for (ll i = 1; i < N + 1; i++) {
        cmi[i] = (cmi[i - 1] + modinv(i)) % MOD;
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll cpi = ((cmi[i + 1] + cmi[N - i] - cmi[1]) % MOD * A[i]) % MOD;
        ans = (ans + cpi) % MOD;
    }
    ll pat = 1;
    for (ll i = 1; i <= N; i++)
        pat = (pat * i) % MOD;
    ans = (ans * pat) % MOD;
    return (ans + MOD) % MOD;
}

int main() {
    input();
    
    cout << solve() << endl;
    
    return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <string>

using namespace std;
using ll = long long;

ll N, X;

void input() {
    cin >> N >> X;
}

void solve() {
    vector<ll> thicks(N);
    vector<ll> patties(N);
    thicks[0] = 1;
    patties[0] = 1;
    for (ll i = 1; i < N; i++) {
        thicks[i] = thicks[i-1] * 2 + 3;
        patties[i] = patties[i-1] * 2 + 1;
    }
    ll ans = 0;
    for (ll i = N-1; i >= 0; i--) {
        auto t = thicks[i], p = patties[i];
        if (X-- == 1)
            break;
        if (X <= t)
            continue;
        X -= t;
        ans += p + 1;
        if (X-- == 1)
            break;
        if (X <= t)
            continue;
        X -= t + 1;
        ans += p;
        break;
    }
    if (X == 1)
        ans++;
    cout << ans << endl;
}

int main() {
    input();
    solve();
    
    return 0;
}
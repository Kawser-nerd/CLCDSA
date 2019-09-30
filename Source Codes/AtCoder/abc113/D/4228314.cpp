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

ll H, W, K;

const ll MOD = 1e9+7;
ll mod(ll x) {return x % MOD;}

void input() {
    cin >> H >> W >> K;
}

void solve() {
    if (W==1) {
        cout << 1 << endl;
        return;
    }
    struct Source {
        ll l, u, r;
    };
    vector<Source> sources(W);
    for (ll n = 0; n < 1ull << (W-1); n++) {
        bool prev = n & 1;
        bool skip = false;
        for (ll i = 1; i < W-1; i++) {
            bool c = n >> i & 1;
            if (c and prev) {
                skip = true;
                break;
            }
            prev = c;
        }
        if (skip) continue;
        prev = false;
        for (ll i = 0; i < W-1; i++) {
            bool c = n >> i & 1;
            if (c) {
                sources[i].l++;
                sources[i+1].r++;
            }
            if (!c and !prev) {
                sources[i].u++;
            }
            if (!c and i == W-2) {
                sources[i+1].u++;
            }
            prev = c;
        }
    }
    cerr << endl;
    vector<array<ll, 8>> dp(H+1);
    dp[0] = {1, 0, 0, 0, 0, 0, 0, 0};
    for (ll h = 1; h <= H; h++) {
        auto &cdp = dp[h], &pdp = dp[h-1];
        for (ll w = 0; w < W; w++) {
            if (w > 0)
                cdp[w] += mod(pdp[w-1] * sources[w].r);
            cdp[w] = mod(cdp[w]);
            cdp[w] += mod(pdp[w] * sources[w].u);
            cdp[w] = mod(cdp[w]);
            if (w < W-1)
                cdp[w] += mod(pdp[w+1] * sources[w].l);
            cdp[w] = mod(cdp[w]);
        }
        for (auto d : cdp)
            cerr << d << ':';
        cerr << endl;
    }
    ll ans = dp.back()[K-1];
    cout << ans << endl;
}

int main() {
    input();
    solve();
    
    return 0;
}
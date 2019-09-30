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

ll N;
vector<ll> C;

const ll MOD = 1e9 + 7;
ll mod(ll x) {return x % MOD;}

void input() {
    cin >> N ;
    C.resize(N);
    for (auto& c : C)
        cin >> c;
}

ll solve() {
    vector<ll> dp(N, 1);
    vector<ll> prevs(200001, -1);
    dp[0] = 1;
    prevs[C[0]] = 0;
    for (ll i = 1; i < N; i++) {
        auto& prevci = prevs[C[i]];
        if (prevci >= 0 and prevci < i - 1) {
            dp[i] = mod(dp[i - 1] + dp[prevci]);
        } else {
            dp[i] = dp[i - 1];
        }
        cerr << dp[i] << endl;
        prevci = i;
    }
    return dp.back();
}

int main() {
    input();
    cout << solve() << endl;
    
    return 0;
}
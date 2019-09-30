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

void input() {
    cin >> N;
}

void solve() {
    if (N == 3) {
        cout << 2 << endl;
        cout << 1 << ' ' << 3 << endl;
        cout << 2 << ' ' << 3 << endl;
        return;
    }
    
    vector<pair<ll, ll>> ans;
    auto n = N - (N%2);
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            if (j == n - i + 1)
                continue;
            ans.push_back({i, j});
        }
    }
    if (N % 2) {
        for (ll i = 1; i <= n; i++)
            ans.push_back({i, N});
    }
    cout << ans.size() << endl;
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;
    
}

int main() {
    input();
    //    cout << solve() << endl;
    solve();
    
    return 0;
}
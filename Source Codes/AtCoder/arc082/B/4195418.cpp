#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

ll N;
vector<ll> P;

void input() {
    cin >> N;
    P.resize(N);
    for (auto& p : P)
        cin >> p;
}

void solve() {
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (P[i] == i + 1) {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
}


int main() {
    input();
    solve();
    
    return 0;
}
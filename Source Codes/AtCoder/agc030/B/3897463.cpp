#include <iostream>
#include <fstream>
#include <vector>
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

ll L, N;
vector<ll> X;

void input() {
    cin >> L >> N;
    X.resize(N);
    for (auto& v : X)
        cin >> v;
//    L = 10, N = 3;
//    X = vector<ll>{2, 7, 9};
}

ll solve() {
    vector<ll> clenl(N), clenr(N);
    clenl[0] = X[0] * 2;
    for (ll i = 1; i < N; i++) {
        clenl[i] = clenl[i - 1] + X[i] * 2;
    }
    vector<ll> RX(N);
    transform(X.begin(), X.end(), RX.begin(), [](ll x) {
        return L - x;
    });
    clenr[N - 1] = RX[N - 1] * 2;
    for (ll i = N - 2; i >= 0; i--) {
        clenr[i] = clenr[i + 1] +  RX[i] * 2;
    }
    
    ll ans = 0;
    for (ll i = 0; i < N * 2; i++) {
        ll k = i % N;
        bool fleft = i < N;
        ll cans = 0;
        if (fleft) {
            ll resi = N - k - 1;
            ll cl = resi / 2;
            cans += clenl[k + cl] - (k > 0 ? clenl[k - 1] : 0);
            if (resi % 2 == 0)
                cans -= X[k + cl];
            ll cr = resi / 2 + resi % 2;
            if (cr > 0) {
                cans += clenr[N - cr];
                if (resi % 2)
                    cans -= RX[N - cr];
            }
        } else {
            ll resi = k;
            ll cl = resi / 2 + resi % 2;
            if (cl > 0) {
                cans += clenl[cl - 1];
                if (resi % 2)
                    cans -= X[cl - 1];
            }
            ll cr = resi / 2;
            cans += clenr[k - cr] - (k < N - 1 ? clenr[k + 1] : 0);
            if (resi % 2 == 0)
                cans -= RX[k - cr];
        }
        
        ans = max(ans, cans);
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;;
    
    return 0;
}
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
vector<ll> B;

void input() {
    cin >> N;
    B.resize(N);
    for (auto& b : B)
        cin >> b;
//    N = 10;
//    B = {1,2,2,3,5,1,6,4,7,3};
}

void solve() {
    for (ll i = 0; i < N; i++) {
        if (B[i] > i + 1) {
            cout << -1 << endl;
            return;
        }
    }

    vector<ll> ans;
    ll len = N;
    while (len) {
        for (ll i = len-1; i >= 0; i--) {
            auto b = B[i];
            if (b == i + 1) {
                ans.push_back(b);
                for (ll k = i; k < len; k++) {
                    B[k] = B[k + 1];
                }
                break;
            }
        }
        len--;
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << endl;
}

int main() {
    input();
    //    cout << solve() << endl;
    solve();

    return 0;
}
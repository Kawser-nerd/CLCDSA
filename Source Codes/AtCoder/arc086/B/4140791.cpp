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
vector<ll> A;

void input() {
    cin >> N;
    A.resize(N);
    for (auto& a : A)
        cin >> a;
}

void solve() {
    auto maxi = max_element(A.begin(), A.end());
    auto mini = min_element(A.begin(), A.end());
    auto put_ans = [](ll l, ll r) {
        cout << l + 1 << ' ' << r + 1 << endl;
    };
    cout << (N - 1) * 2 << endl;
    if (abs(*maxi) >= abs(*mini)) {
        for (auto it = A.begin(); it != A.end(); ++it) {
            if (it != maxi)
                put_ans(maxi - A.begin(), it - A.begin());
        }
        for (ll i = 0; i < N - 1; i++)
            put_ans(i, i + 1);
    } else {
        for (auto it = A.begin(); it != A.end(); ++it) {
            if (it != mini)
                put_ans(mini - A.begin(), it - A.begin());
        }
        for (ll i = N - 1; i > 0; i--)
            put_ans(i, i - 1);
    }
}


int main() {
    input();
    solve();
    
    return 0;
}
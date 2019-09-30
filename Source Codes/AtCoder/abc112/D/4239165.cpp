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

void solve() {
    ll ans = 0;
    for (ll n = 1; n <= min(double(M / N), sqrt(M)); n++) {
        if (M % n == 0) {
            if (n >= N) {
                ans = M / n;
                break;
            }
            ans = n;
        }
    }
    cout << ans << endl;
}




int main() {
    input();
    solve();
    
    return 0;
}
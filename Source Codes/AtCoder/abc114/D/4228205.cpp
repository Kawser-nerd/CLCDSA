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
    vector<ll> divisors(N+1);
    for (ll n = 2; n <= N; n++) {
        ll cn = n;
        for (ll k = 2; k <= n; k++) {
            while (cn % k == 0) {
                divisors[k]++;
                cn /= k;
            }
        }
    }
    for (ll i = 2; i < N+1; i++)
        cerr << "div[" << i << "=" << divisors[i] << endl;
    auto num_of_greater_divs = [&divisors](ll n) {
        ll res = 0;
        for (auto d : divisors) {
            if (d >= n-1)
                res++;
        }
        return res;
    };
    ll n75 = num_of_greater_divs(75);
    ll n25 = num_of_greater_divs(25);
    ll n15 = num_of_greater_divs(15);
    ll n5 = num_of_greater_divs(5);
    ll n3 = num_of_greater_divs(3);
    ll ans = n75 + n25 * (n3-1) + n15 * (n5-1) + n5 * (n5-1) * (n3-2) / 2;
    cout << ans << endl;
}

int main() {
    input();
    solve();
    
    return 0;
}
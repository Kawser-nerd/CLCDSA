#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

ll smd(ll x) {
    ll sm = 0;
    while (x) {
        sm += x % 10;
        x /= 10;
    }
    return sm;
}
int main() {
    ll k, m;
    cin >> k >> m;
    if (m < 100100) {
        ll ans = 0;
        for (ll i = 0; i <= m; i++) {
            if (smd(i)%k == i%k) ans++;
        }
        cout << ans-1 << endl;
        return 0;
    }
    ll ans = 0;
    // upper
    {
        ll upm = m - (m%100000);
        ll A = upm % k;
        ll B = smd(m/100000) % k;
        for (ll i = 0; i <= m%100000; i++) {
            ll C = i%k;
            ll D = smd(i)%k;
            if ((D-C+k)%k == (A-B+k)%k) ans++;
        }
    }
    // lower
    vector<ll> s;
    for (ll i = 0; i < 100000; i++) {
        ll C = i%k;
        ll D = smd(i)%k;
        s.push_back((D-C+k)%k);
    }
    sort(s.begin(), s.end());
    for (ll i = 0; i < m/100000; i++) {
        ll A = i*100000 % k;
        ll B = smd(i) % k;
        ans += upper_bound(s.begin(), s.end(), (A-B+k)%k) - lower_bound(s.begin(), s.end(), (A-B+k)%k);
    }
    cout << ans-1 << endl;
    return 0;
}
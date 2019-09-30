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
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

const int MP = 100100;
vector<int> pr;
vector<ull> bpr;

void first() {
    bool used[MP] = {};
    for (int i = 2; i < MP; i++) {
        if (used[i]) continue;
        pr.push_back(i);
        ull x = ((__int128(1)<<64) + i-1 ) / i;
        bpr.push_back(x);
        for (int j = 2*i; j < MP; j += i) {
            used[j] = true;
        }
    }
}

map<ll, int> fact(ll n) {
    int pc = (int)pr.size();
    map<ll, int> mp;
    while (n % 2 == 0) {
        n /= 2;
        mp[2]++;
    }
    while (n % 3 == 0) {
        n /= 3;
        mp[3]++;
    }
    for (int i = 2; i < pc; i++) {
        ll d = pr[i]; ull rd = bpr[i];
        while (true) {
            ll nd = __int128(n)*rd >> 64;
            if (nd * d != n) break;
            n = nd;
            mp[d]++;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}


int main() {
    first();
    using F = vector<ll>;
    map<F, F> g;
    map<F, int> a;
    int n;
    scanf("%d", &n);
    bool one = false;
    for (int i = 0; i < n; i++) {
        if (i % 1000 == 0) {
//            cout << i << " " << gc << endl;
        }
        ll s;
        scanf("%lld", &s);
        map<ll, int> fac = fact(s);
        F d0, d1;
        for (auto p: fac) {
            p.second %= 3;
            if (p.second == 1) {
                d0.push_back(p.first);
                d1.push_back(p.first);
                d1.push_back(p.first);
            } else if (p.second == 2) {
                d0.push_back(p.first);
                d0.push_back(p.first);
                d1.push_back(p.first);
            }
        }
        sort(d0.begin(), d0.end());
        sort(d1.begin(), d1.end());
        if (d0.size() == 0) {
            one = true;
            continue;
        }
        g[d0] = d1; g[d1] = d0;
        a[d0]++;
    }

    int ans = 0;
    for (auto p: g) {
        ans += max(a[p.first], a[p.second]);
    }
    cout << ans/2 + (one ? 1 : 0) << endl;
    return 0;
}
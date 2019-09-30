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
 
struct Prime {
    int n;
    vector<bool> used;
    vector<int> pr;
    vector<ull> bpr;
    Prime(int n) : n(n) {
        used = vector<bool>(n+1, false);
        for (int i = 2; i <= n; i++) {
            if (used[i]) continue;
            pr.push_back(i);
            bpr.push_back(((__int128(1)<<64)+i-1) / i);
            for (int j = 2*i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }    
    map<ll, int> fact(ll x) {
        assert(x <= (ll)n*n);
        int pc = (int)pr.size();
        map<ll, int> mp;
        for (int i = 0; i < pc; i++) {
            ll d = pr[i]; ull rd = bpr[i];
//            if (x < d*d) break; ???
            while (true) {
                ll xd = __int128(x)*rd >> 64;
                if (xd * d != x) break;
                x = xd;
                mp[d]++;
            }
        }
        if (x > 1) mp[x]++;
        return mp;
    }
};
 
const int MP = 100100;
 
ll mul(ll a, ll b) {
    if (TEN(12)/a < b) return TEN(12);
    return a*b;
}
 
int main() {
    Prime pr(MP);
    using P = pair<ll, ll>;
    map<ll, P> g;
    int n;
    scanf("%d", &n);
    bool one = false;
    for (int i = 0; i < n; i++) {
        ll s;
        scanf("%lld", &s);
        map<ll, int> fac = pr.fact(s);
        ll d0 = 1, d1 = 1;
        for (auto p: fac) {
            p.second %= 3;
            if (p.second == 1) {
                d0 = mul(d0, p.first);
                d1 = mul(d1, p.first);
                d1 = mul(d1, p.first);
            } else if (p.second == 2) {
                d0 = mul(d0, p.first);
                d0 = mul(d0, p.first);
                d1 = mul(d1, p.first);
            }
        }
        if (d0 == 1) {
            one = true;
            continue;
        }
        if (d0 < d1) {
            g[d0].first++;
        } else {
            g[d1].second++;
        }
    }
 
    int ans = 0;
    for (auto p: g) {
        ans += max(p.second.first, p.second.second);
    }
    cout << ans + (one ? 1 : 0) << endl;
    return 0;
}
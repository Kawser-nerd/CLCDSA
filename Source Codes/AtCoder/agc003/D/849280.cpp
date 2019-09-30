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
constexpr ll TEN(int n) {return (n==0)?1:10*TEN(n-1);}
ll gcd(ll a, ll b) {return (b==0) ? a : gcd(b, a%b);}

template<class T>
T pow(T x, ll n, T md) {
    T r = 1;
    while (n) {
        if (n & 1) r = (r*x)%md;
        x = (x*x)%md;
        n >>= 1;
    }
    return r;
}


ll rand_int(ll l, ll r) { //[l, r)
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r-1)(gen);
}

const int MP = 100100;
vector<int> pr;

void first() {
    bool used[MP] = {};
    for (int i = 2; i < MP; i++) {
        if (used[i]) continue;
        pr.push_back(i);
        for (int j = 2*i; j < MP; j += i) {
            used[j] = true;
        }
    }
}

map<ll, int> factsmall(ll n) {
    map<ll, int> mp;
    for (ll d: pr) {
        if (n < d*d) break;
        while (n % d == 0) {
            n /= d;
            mp[d]++;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ll d = n-1;
    while (d % 2 == 0) d /= 2;
//    vector<ll> alist{2,7,61}; // n < 2^32
    vector<ll> alist{2,3,1662803}; // n < 1.12e12
//    vector<ll> alist{2,3,5,7,11,13,17,19,23,29,31,37}; // n < 2^64
    for (ll a: alist) {
        if (n <= a) break;
        ll t = d;
        ll y = pow<__int128>(a, t, n); //over
        while (t != n-1 && y != 1 && y != n-1) {
            y = __int128(y)*y % n; //flow
            t <<= 1;
        }
        if (y != n-1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}


int gc = 0;

map<ll, int> prefact(ll n) {
    map<ll, int> mp;
    for (ll d: pr) {
        if (1000 < d) break;
        while (n % d == 0) {
            n /= d;
            mp[d]++;
        }
    }
    if (isPrime(n)) {
        mp[n]++;
        return mp;
    }
    map<ll, int> mp1 = factsmall(n);
    for (auto p: mp1) {
        mp[p.first] += p.second;
    }
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
        map<ll, int> fac = prefact(s);
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
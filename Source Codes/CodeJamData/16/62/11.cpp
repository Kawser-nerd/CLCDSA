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

template<class T>
T pow(T x, ll n) {
    T r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}


template<uint MD>
struct ModInt {
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    const ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    const ModInt operator-(const ModInt &r) const {return make(normS(v+normS(MD-r.v)));}
    const ModInt operator*(const ModInt &r) const {return make((ull)v*r.v%MD);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    static ModInt inv(const ModInt &x) {
        return pow(ModInt(x), MD-2);
    }
};

using Mint = ModInt<TEN(9)+7>;
const int MN = 10100100;

Mint fact[MN], iFac[MN];
void first() {
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i-1]*i;
    }
    for (int i = 0; i < MN; i++) {
        iFac[i] = Mint::inv(fact[i]);
    }
}

Mint C(int n, int k) {
    return fact[n]*iFac[k]*iFac[n-k];
}

Mint calc(int n) {
    Mint ans = 0;
    for (int i = 1; i+1 <= n; i+=2) {
        ans += C(n, i+1) * fact[n-(i+1)] * i;
    }
    if (n % 2 == 1) ans += 1;
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k; k--;
    //[0..n-1), k-1, k
    Mint l = fact[k]-calc(k), r = fact[n-1-k]-calc(n-1-k);
    Mint ans = fact[n-1] - (C(n-1, k) * l * r);
    cout << (iFac[n-1]*ans).v << endl;
}

int main() {
    first();
/*    for (int i = 0; i <= 10 ; i++) {
        printf("DEB %d %d\n", i, calc(i).v);
    }*/
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
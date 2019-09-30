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
    ModInt() : v(0) {}
    ModInt(ll v) : v(normS(v%MD+MD)) {}
    uint value() const {return v;}
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

const int MN = 4040;
Mint g[MN][MN];
Mint C[MN][MN];
Mint fact[2*MN], iFac[2*MN];
void first() {
    fact[0] = 1;
    for (int i = 1; i < 2*MN; i++) {
        fact[i] = fact[i-1]*i;
    }
    for (int i = 0; i < 2*MN; i++) {
        iFac[i] = Mint::inv(fact[i]);
    }
    C[0][0] = 1;
    for (int i = 1; i < MN; i++) {
        C[i][0] = C[i-1][0];
        for (int j = 1; j < MN; j++) {
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
}
int main() {
    first();
    int m;
    cin >> m;
    int a[m], b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    Mint off = 0;
    for (int i = 0; i < m; i++) {
//        off += C[2*a[i]+2*b[i]][2*b[i]];
        off += fact[2*a[i]+2*b[i]]*iFac[2*a[i]]*iFac[2*b[i]];
    }
    for (int i = 0; i < m; i++) {
        g[2010-a[i]][2010-b[i]] += 1;
    }
    for (int i = 1; i < MN; i++) {
        for (int j = 1; j < MN; j++) {
            g[i][j] += g[i-1][j]+g[i][j-1];
        }
    }
    Mint ans = 0;
    for (int i = 0; i < m; i++) {
        ans += g[2010+a[i]][2010+b[i]];
    }
    ans -= off;
    ans *= Mint::inv(2);
    cout << ans.value() << endl;
    return 0;
}
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

const int MN = 30;


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

using P = vector<int>;
using Mint = ModInt<TEN(9)+7>;

int V;
int a[MN];
bool f[MN*MN];
int fsm[MN*MN];
using Q = pair<P, int>;
map<Q, Mint> mp;
Mint solve(P p, int n) {
    if (mp.count(Q(p, n))) return mp[Q(p, n)];
    int m = (int)p.size();
    Mint ans = 0;
    if (n == V*(V-1)/2) {
        return 1;
    }
    if (f[n]) {
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                vector<int> v;
                for (int k = 0; k < m; k++) {
                    if (k == i) continue;
                    if (k == j) continue;
                    v.push_back(p[k]);
                }
                v.push_back(p[i]+p[j]);
                sort(v.begin(), v.end());
                ans += solve(v, n+1) * p[i]*p[j];
            }
        }
    } else {
        int sm = 0;
        for (int d: p) {
            sm += d*(d-1)/2;
        }
        sm -= n;
        ans += solve(p, n+1) * sm;
    }
/*    printf("ans(%d) n(%d):",ans.v, n);
    for (int d: p) {
        printf("%d, ", d);
    }
    printf("\n");*/
    return mp[Q(p, n)] = ans;
}

int main() {
    cin >> V;
    for (int i = 0; i < V-1; i++) {
        int a;
        cin >> a; a--;
        f[a] = true;
    }
    fsm[0] = 0;
    for (int i = 0; i < V*(V-1)/2; i++) {
        fsm[i] = fsm[i-1];
        if (f[i-1]) fsm[i]++;
    }
    P v;
    for (int i = 0; i < V; i++) {
        v.push_back(1);
    }
    cout << solve(v, 0).value() << endl;
    return 0;
}
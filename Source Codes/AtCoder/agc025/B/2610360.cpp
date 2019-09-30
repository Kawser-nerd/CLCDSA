#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

//int main() {
//    return 0;
//}

constexpr long long M = 998244353;

int N, A, B;
long long K;

typedef long long ll;

long long mod = M;
ll f[300010] = {0}; // f(n) = (n!) % mod

// ??????? O(log n)
ll mod_pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x*x % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return mod_pow(x, mod-2) % mod;
}

// nCr % mod
ll comb(int n, int r){
    return (((f[n] * mod_inv(f[r])) % mod) * mod_inv(f[n-r])) % mod;
}

class {
unsigned y = 2463534242;
public:
unsigned next() {
    return y ^= (y ^= (y ^= y << 13) >> 17) << 5;
}
int next(int b) {
    return next() % b;
}
int next(int a, int b) {
    return next(b - a) + a;
}
double nextDouble(double b = 1) {
    return b * next() / 4294967296.0;
}
double nextDouble(double a, double b) {
    return nextDouble(b - a) + a;
}
int operator() (int b) {
    return next(b);
}
} rando;

int main() {
    f[0] = f[1] = 1;
    for(int i=2; i<=300005; ++i) f[i] = (i * f[i-1]) % mod;
    while (cin >> N >> A >> B >> K) {
        long long re = 0;
        for (int i = 0; i <= N; ++i) {
            if ((K - (long long)i * A) % B == 0 && (K - (long long)i * A) / B >= 0 && (K - (long long)i * A) / B <= N) {
                int j = (int)((K - (long long)i * A) / B);
                re += comb(N, i) * comb(N, j) % M;
                re %= M;
            }
        }
        cout << re << endl;
    }
    return 0;
} ./Main.cpp:58:20: warning: unsequenced modification and access to 'y' [-Wunsequenced]
    return y ^= (y ^= (y ^= y << 13) >> 17) << 5;
             ~~    ^
1 warning generated.
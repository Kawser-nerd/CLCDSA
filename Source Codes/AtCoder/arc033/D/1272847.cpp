#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;

ll powmod(ll x, ll y, ll p) { // O(log y)
    assert (0 <= x and x < p);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
    }
    return z;
}
ll inv(ll x, ll p) { // p must be a prime, O(log p)
    assert ((x % p + p) % p != 0);
    return powmod(x, p-2, p);
}
constexpr int mod = 1e9+7;

int solve(int n, vector<int> const & f, int x) {
    if (0 <= x and x < n+1) {
        return f[x];
    }
    // Lagrange interpolation with O(N \log mod)
    ll a = 1;
    repeat (i,n+1) {
        a = a * (x - i +(ll) mod) % mod;
    }
    vector<int> b(n+2);
    b[0] = 1;
    repeat (i,n+1) {
        b[i+1] = b[i] *(ll) (i+1) % mod;
    }
    ll y = 0;
    repeat (i,n+1) {
        ll ai = a * inv((x - i +(ll) mod) % mod, mod) % mod;
        ll bi = inv(b[i] *(ll) b[n-i] % mod, mod);
        if ((n-i) % 2 == 1) bi = mod - bi;
        y += f[i] * ai % mod * bi % mod;
    }
    y %= mod;
    return y;
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> a(n+1); repeat (i,n+1) scanf("%d", &a[i]);
    int t; scanf("%d", &t);
    // solve
    int at = solve(n, a, t);
    // output
    printf("%d\n", at);
    return 0;
}
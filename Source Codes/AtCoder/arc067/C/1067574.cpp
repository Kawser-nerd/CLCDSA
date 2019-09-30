#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i,m,n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define debug(x) #x << " = " << (x) << " "
using ll = long long;
using namespace std;
template <class T> void setmax(T & a, T const & b) { if (a < b) a = b; }
template <class T> void setmin(T & a, T const & b) { if (b < a) a = b; }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
const int mod = 1e9+7;
 
ll powmod(ll x, ll y) { // O(log y)
    assert (y >= 0);
    x %= mod; if (x < 0) x += mod;
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z *(ll) x % mod;
        x = x *(ll) x % mod;
    }
    return z;
}
ll inv(ll x) { // p must be a prime, O(log p)
    assert ((x % mod + mod) % mod != 0);
    return powmod(x, mod-2);
}
ll fact(ll n) {
    static vector<ll> memo(1,1);
    if (memo.size() <= n) {
        ll l = memo.size();
        memo.resize(n+1);
        repeat_from (i,l,n+1) memo[i] = memo[i-1] *(ll) i % mod;
    }
    return memo[n];
}
ll choose(ll n, ll r) { // O(n) at first time, otherwise O(1)
    if (n < r) return 0;
    r = min(r, n - r);
    return fact(n) *(ll) inv(fact(n-r)) % mod *(ll) inv(fact(r)) % mod;
}
 
int main() {
    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    vector<ll> cur(n+1), prv;
    cur[0] = 1;
    repeat_from (size,a,b+1) {
        prv = cur;
        repeat_from (count,c,d+1) {
            ll k = fact(size*count) *(ll) inv(powmod(fact(size), count)) % mod * inv(fact(count)) % mod;
            repeat (i,n) if (i + size*count < n+1 and prv[i]) {
                cur[i + size*count] += prv[i] *(ll) choose(n-i, size*count) % mod * k % mod;
            }
        }
        repeat (i,n+1) cur[i] %= mod;
    }
    cout << cur[n] << endl;
    return 0;
}
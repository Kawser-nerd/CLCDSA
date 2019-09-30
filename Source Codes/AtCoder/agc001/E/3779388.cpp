// includes {{{
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

const int N = 2e5;
const int X = 2000;
const int mod = 1e9 + 7;

int a[N], b[N];

int n;

// WARN : use H with larger N
/// --- Modulo Factorial {{{ ///
template < int N, int mod = (int) 1e9 + 7 >
struct Factorial {
  constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = 0;
    return b == 0 ? (x = 1, y = 0, a) : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  constexpr ll modinv(ll a) {
    ll x = 0, y = 0;
    extgcd(a, mod, x, y);
    return (x + mod) % mod;
  }
  int arr[N + 1], inv[N + 1];
  ll operator[](int i) const { return arr[i]; }
  Factorial() : arr(), inv() {
    arr[0] = 1;
    for(int i = 1; i <= N; i++) {
      arr[i] = (ll) i * arr[i - 1] % mod;
    }
    inv[N] = modinv(arr[N]);
    for(int i = N - 1; i >= 0; i--) {
      inv[i] = (ll)(i + 1) * inv[i + 1] % mod;
    }
  }
  ll C(int n, int r) const {
    if(n < 0 || r < 0 || n < r) return 0;
    return (ll) arr[n] * inv[r] % mod * inv[n - r] % mod;
  }
  ll H(int n, int r) const { return C(n + r - 1, r); }
};
/// }}}--- ///

Factorial< X * 4, mod > fact;

// LoopArray {{{
#include <array>
template < class T, size_t N >
class LoopArray : public array< T, N > {
  using Index = ll;

public:
  T &at(Index i) { return *this[i]; }
  const T &at(Index i) const { return *this[i]; }
  T &operator[](Index i) {
    i %= Index(N);
    if(i < 0) i += Index(N);
    return array< T, N >::operator[](i);
  }
  const T &operator[](Index i) const {
    i %= Index(N);
    if(i < 0) i += Index(N);
    return array< T, N >::operator[](i);
  }
};
// }}}

template < class T, size_t N >
using myarray = LoopArray< T, N >;

/// --- ModInt Library {{{ ///
#include <ostream>
template < ll mod = (ll) 1e9 + 7 >
struct ModInt {
  // math {{{
  static inline ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d;
    return b == 0 ? (x = 1, y = 0, a) : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  static inline ll modinv(ll a) {
    ll x = 0, y = 0;
    extgcd(a, mod, x, y);
    if(x < 0) x += mod;
    return x;
  }
  static inline ll modpow(ll a, ll b) {
    if(b < 0) b = -b, a = modinv(a);
    ll r = 1;
    a %= mod;
    while(b) {
      if(b & 1) r = r * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return r;
  }
  // }}}

  ll val;
  constexpr ModInt() : val(0) {}
  constexpr ModInt(ll t) {
    val = t % mod;
    if(val < 0) val += mod;
  }

private:
  // strict constructor
  constexpr ModInt(ll t, int) : val(t) {}

public:
  template < class T >
  explicit operator T() {
    return T(val);
  }
  // ModInt <arithmetic-operator>[=] ModInt {{{
  ModInt operator+(ModInt const &rhs) const {
    ModInt tmp = *this;
    tmp += rhs;
    return tmp;
  }
  ModInt operator-(ModInt const &rhs) const {
    ModInt tmp = *this;
    tmp -= rhs;
    return tmp;
  }
  ModInt operator*(ModInt const &rhs) const {
    ModInt tmp = *this;
    tmp *= rhs;
    return tmp;
  }
  ModInt operator/(ModInt const &rhs) const {
    ModInt tmp = *this;
    tmp /= rhs;
    return tmp;
  }
  ModInt &operator+=(ModInt const &rhs) {
    val = val + rhs.val;
    if(val >= mod) val -= mod;
    return *this;
  }
  ModInt &operator-=(ModInt const &rhs) { return *this += -rhs; }
  ModInt &operator*=(ModInt const &rhs) {
    val = val * rhs.val % mod;
    return *this;
  }
  ModInt &operator/=(ModInt const &rhs) { return *this *= rhs.inv(); }
  // }}}
  // increment, decrement {{{
  ModInt operator++(int) {
    ModInt tmp = *this;
    val = val + 1;
    if(val >= mod) val = 0;
    return tmp;
  }
  ModInt operator--(int) {
    ModInt tmp = *this;
    val = val == 0 ? mod - 1 : val - 1;
    return tmp;
  }
  ModInt &operator++() {
    val = val + 1;
    if(val >= mod) val = 0;
    return *this;
  }
  ModInt &operator--() {
    val = val == 0 ? mod - 1 : val - 1;
    return *this;
  }
  // }}}
  ModInt operator-() const { return ModInt(val == 0 ? 0 : mod - val, 0); }
  // ModInt <arithmetic-operator>[=] T {{{
  template < typename T >
  ModInt operator+(T const &rhs) const {
    return ModInt(val + rhs % mod);
  }
  template < typename T >
  ModInt operator-(T const &rhs) const {
    return ModInt(mod + val - rhs % mod);
  }
  template < typename T >
  ModInt operator*(T const &rhs) const {
    return ModInt(val * (rhs % mod));
  }
  template < typename T >
  ModInt operator/(T const &rhs) const {
    return ModInt(val * modinv(rhs));
  }
  template < typename T >
  ModInt &operator+=(T const &rhs) {
    val = (mod + val + rhs % mod) % mod;
    return *this;
  }
  template < typename T >
  ModInt &operator-=(T const &rhs) {
    val = (mod + val - rhs % mod) % mod;
    return *this;
  }
  template < typename T >
  ModInt &operator*=(T const &rhs) {
    val = val * (mod + rhs % mod) % mod;
    return *this;
  }
  template < typename T >
  ModInt &operator/=(T const &rhs) {
    val = val * modinv(rhs, mod) % mod;
    return *this;
  }
  // }}}
  ModInt inv() const { return ModInt(modinv(val), 0); }
  ModInt operator~() const { return inv(); }
  friend ostream &operator<<(ostream &os, ModInt const &mv) {
    os << mv.val;
    return os;
  }
  // T <arithmetic-operator> ModInt {{{
  friend constexpr ModInt operator+(ll a, ModInt const &mv) {
    return ModInt(a % mod + mv.val);
  }
  friend constexpr ModInt operator-(ll a, ModInt const &mv) {
    return ModInt(a % mod - mv.val);
  }
  friend constexpr ModInt operator*(ll a, ModInt const &mv) {
    return ModInt((mod + a % mod) * mv.val % mod, 0);
  }
  friend constexpr ModInt operator/(ll a, ModInt const &mv) {
    return ModInt((mod + a % mod) * modinv(mv.val) % mod, 0);
  }
  // }}}
  // power {{{
  ModInt operator^(ll x) const { return pow(*this, x); }
  ModInt &operator^=(ll x) {
    val = modpow(val, x);
    return *this;
  }
  friend ModInt pow(ModInt x, ll y) { return ModInt(modpow(x.val, y), 0); }
  // }}}
};
/// }}}--- ///

using mint = ModInt<>;

myarray< myarray< mint, 2 * X + 10 >, 2 * X + 10 > dp;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  mint ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    ans -= fact.C((a[i] + b[i]) * 2, a[i] * 2);
    dp[-a[i]][-b[i]]++;
  }
  for(int i = -X; i <= X; i++)
    for(int j = -X; j <= X; j++) {
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
    }
  for(int i = 0; i < n; i++) {
    ans += dp[a[i]][b[i]];
  }
  cout << ans / 2 << endl;
  return 0;
}
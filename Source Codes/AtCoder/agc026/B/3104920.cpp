#if defined(LOCAL)
#define PROBLEM_NAME "b"
const double _max_double_error = 1e-9;
#include "testutils.h"
#define L(x...) (debug(x, #x))
#define I(x, ...) (x)
#define C(x...) CHECK(x)
#else
#define L(x, ...) (x)
#define I(x, ...) (x)
#define C(x, ...) ;
#endif
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <limits>
#include <numeric>

using namespace std;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ii = pair<int,int>; using lu = unsigned long long; using l = long long;
using vs = vector<string>; using vii = vector<ii>;
using vl = vector<l>; using vvl = vector<vl>; using vvvl = vector<vvl>;
using ll = pair<l,l>; using vll = vector<ll>; using vvll = vector<vll>;
using vb = vector<bool>; using vvb = vector<vb>;
using vd = vector<double>; using vvd = vector<vd>;
using mll = unordered_map<l, l>;
const l INF = numeric_limits<l>::max();
const double EPS = 1e-10; static constexpr auto PI = 3.1415926;
const l e0=1, e3=1000, e5=100000, e6=10*e5, e7=10*e6, e8=10*e7, e9=10*e8;
const char lf = '\n';
#define all(x) begin(x), end(x)
#define F(a,b,c) for (l a = l(b); a < l(c); a++)
#define B(a,b,c) for (l a = l(c) - 1; a >= l(b); a--)
#define VVL(x, a, b, i) vvl x(a, vl(b, l(i)));
#define VVVL(x, a, b, c, i) vvvl x(a, vvl(b, vl(c, l(i))));

const l MOD = e9 + 7; // end of template

l gcd(l a, l b) {
  while (b) { a %= b; swap(a, b); }
  return a;
}

l lcm(l a, l b) { return a / (gcd(a, b)) * b; }

l sign(l n) {
  if (n < 0) return -1;
  if (n == 0) return 0;
  return 1;
}

// conruent modulo, works for negative
l cong(l x, l mod) {
  return (x % mod + mod) % mod;
}

// (a * b) % mod, safe for l near max
l mult_mod(l a, l b, l mod) {
  l x = 0;
  while (b) {
    if (b % 2) x = (x + a) % mod;
    a = (a * 2) % mod;
    b /= 2;
  }
  return x;
}

// (base^power) % mod, safe for l near max
l pow_mod(l base, l power, l mod) {
  l r = 1;
  while (power) {
    if (power % 2) r = mult_mod(r, base, mod);
    base = mult_mod(base, base, mod);
    power /= 2;
  }
  return r;
}

l divup(l a, l b) { // ceil div
  return (a + b - 1) / b;
}

// return gcd(a, b) and set x, y: a * x + b * y = gcd(a, b)
l extended_euclid(l a, l b, l& x, l& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  l d = extended_euclid(b, a % b, x, y);
  l t = y;
  y = x - (a / b) * y;
  x = t;
  return d;
}

// return b: a * b = 1 (mod n)
l inverse_mod(l a, l n) {
  l x, y;
  l d = extended_euclid(a, n, x, y);
  if (d != 1) return 0;
  return cong(x, n);
}

// single combintions k from n
l nCr(l n, l k, l mod) {
  l a = 1;
  for (l i = n; i > n - k; i--) a = mult_mod(a, i, mod);
  l b = 1;
  F(i, 1, k + 1) b = mult_mod(b, i, mod);
  b = inverse_mod(b, mod);
  return mult_mod(a, b, mod);
}

// precompute all combinations up to (n n)
vvl combinations(l n, l mod) {
  vvl c(n + 1, vl(n + 1));
  F(i, 0, n + 1) {
    c[i][0] = 1;
    F(j, 1, i + 1) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  return c;
}

// l on the ring of MOD, put l arg to the right: lm = lm + l
struct lm {
  l raw;
  lm(): raw(0) {}
  lm(l x): raw(x) {}
  lm(lm const& x): raw(x.raw) {}
  lm(lm&& x) { swap(*this, x); }
  friend void swap(lm& a, lm& b) { swap(a.raw, b.raw); }
  lm& operator = (l x) { raw = x; return *this; }
  lm& operator = (lm x) { swap(*this, x); return *this; }
  void operator += (const lm x) { raw = cong(raw + x.raw, MOD); }
  lm operator + (const lm x) { lm z(*this); z += x; return z; }
  void operator -= (const lm x) { raw = cong(raw - x.raw, MOD); }
  lm operator - (const lm x) { lm z(*this); z -= x; return z; }
  void operator *= (const lm x) { raw = cong(raw * x.raw, MOD); }
  lm operator * (const lm x) { lm z(*this); z *= x; return z; }
  void operator /= (const lm x) { raw = cong(raw * inverse_mod(x.raw, MOD), MOD); }
  lm operator / (const lm x) { lm z(*this); z /= x; return z; }
};
using vlm = vector<lm>;

bool possible(l a, l b, l c, l d) {
  if (d < b || a < b) return false;
  if (c >= b) return true;
  l k = gcd(d, b);
  l t = a - (a - c - 1) / k * k;
  return t >= b;
}

void solve(istream& in, ostream& out) {
  l tcc; in >> tcc;
  F(i, 0, tcc) {
    l a, b, c, d; in >> a >> b >> c >> d;
    out << (possible(a, b, c, d) ? "Yes" : "No") << lf;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(15);
#if defined(LOCAL)
  // _generate_random_test = generate_random;
  // _solve_brute = solve_brute;
  // _player_b = player_b;
  // _custom_solution_checker = solution_checker;
  maybe_run_tests(cin, cout);
#else
  solve(cin, cout);
#endif
}
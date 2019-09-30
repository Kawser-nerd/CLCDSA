/* -------------------------------- Template -------------------------------- */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }

// template<typename T> constexpr T inf = [](){ assert(false); };
// template<> constexpr int inf<int> = 1e9;
// template<> constexpr ll inf<ll> = 1e18;
// template<> constexpr ld inf<ld> = 1e30;

struct yes_no : std::numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

void solve();

int main() {
  std::locale loc(std::locale(), new yes_no);
  std::cout << std::boolalpha << std::setprecision(12) << std::fixed;
  std::cout.imbue(loc);
  solve();
  return 0;
}

using namespace std;

/* -------------------------------- Library -------------------------------- */

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
};

const int mod = 1000000007;
using Mod = Modulo<mod, true>;

typedef Mod Data;

struct PST {
  Data val, mult;
  PST *l, *r;
  PST() : val(0), mult(1), l(nullptr), r(nullptr) {}
  PST(Data val, Data mult, PST *l, PST *r) :
    val(val), mult(mult), l(l), r(r) {}
};

Data value(PST* ptr) { if (ptr) return ptr->val; else return 0; }
Data mult(PST* ptr) { if (ptr) return ptr->mult; else return 0; }
PST *left(PST* ptr) { if (ptr) return ptr->l; else return nullptr; }
PST *right(PST* ptr) { if (ptr) return ptr->r; else return nullptr; }
PST *make_pst(int n) {
  if (n == 0) return new PST();
  PST *ptr = make_pst(n-1);
  return new PST(0, 1, ptr, ptr);
}

PST *update(PST *ptr, int lpos, int rpos, Data m, Data a, int la = 0, int ra = (1 << 17)) {
  if (rpos <= la || ra <= lpos) {
    if (m == 1) return ptr;
    return new PST(value(ptr) * m, mult(ptr) * m, left(ptr), right(ptr));
  }
  if (lpos <= la && ra <= rpos) {
    return new PST(value(ptr) * m + a, mult(ptr) * m, left(ptr), right(ptr));
  }
  int mid = (la + ra) / 2;
  PST *l = update(left(ptr),  lpos, rpos, mult(ptr) * m, a, la, mid);
  PST *r = update(right(ptr), lpos, rpos, mult(ptr) * m, a, mid, ra);
  return new PST(value(l) + value(r), Mod(1), l, r);
}

Data query(PST *ptr, int lpos, int rpos, int la = 0, int ra = (1 << 17)) {
  if (rpos <= la || ra <= lpos) return Data(0);
  if (lpos <= la && ra <= rpos) return ptr->val;
  int mid = (la + ra) / 2;
  Data res = 0;
  res += query(ptr->l, lpos, rpos, la, mid);
  res += query(ptr->r, lpos, rpos, mid, ra);
  return res * ptr->mult;
}

void output(tuple<PST*, set<int>, Mod, Mod> x) {
  cout << "{--" << endl << "  ";
  for (int i: get<1>(x)) cout << i << " ";
  cout << endl << "  ";
  cout << int(get<2>(x)) << ", " << int(get<3>(x)) << endl;
  cout << "--}" << endl;
}

/* ---------------------------------- Main ---------------------------------- */

PST *zero = make_pst(17);

tuple<PST*,set<int>,Mod,Mod> parse(const vector<int> &a, int &p) {
  if (a[p] > 0) {
    PST *ptr = update(zero, a[p], a[p] + 1, Mod(1), Mod(1));
    set<int> se; se.insert(a[p]);
    ++p;
    return make_tuple(ptr, se, Mod(1), Mod(0));
  }
  else if (a[p] < 0) {
    Mod c = -a[p]; ++p;
    auto res = parse(a, p);
    Mod sum = query(get<0>(res), 0, 1 << 17);
    Mod sq = get<2>(res);
    return make_tuple(update(get<0>(res), 0, 1 << 17, Mod(c), Mod(0)),
                      move(get<1>(res)),
                      sq * Mod(c) * Mod(c),
                      get<3>(res) * Mod(c) + c * (c - 1) * (sum * sum - sq) / Mod(4));
  }
  else {
    ++p;
    auto res1 = parse(a, p);
    auto res2 = parse(a, p);
    bool flag = true;
    if (get<1>(res1).size() < get<1>(res2).size()) {
      swap(res1, res2);
      flag = false;
    }

    PST *ptr = get<0>(res1);
    set<int> se = move(get<1>(res1));
    Mod sq = get<2>(res1);
    Mod res = get<3>(res1) + get<3>(res2);

    for (int i: get<1>(res2)) {
      const Mod c1 = query(ptr, i, i + 1);
      const Mod c2 = query(get<0>(res2), i, i + 1);
      sq -= c1 * c1;
      sq += (c1 + c2) * (c1 + c2);
      se.insert(i);
      if (flag) res += query(ptr, 0, i) * c2;
      else res += query(ptr, i + 1, 1 << 17) * c2;
    }
    for (int i: get<1>(res2)) {
      const Mod c2 = query(get<0>(res2), i, i + 1);
      ptr = update(ptr, i, i + 1, Mod(1), c2);
    }
    return make_tuple(ptr, move(se), sq, res);
  }
}

void solve() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int &i: a) cin >> i;
  reverse(ALL(a));
  int p = 0;
  auto res = parse(a, p);
  cout << int(get<3>(res)) << endl;
  return;
}
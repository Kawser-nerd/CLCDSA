#include <stdint.h>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);
static const ll MOD = 1000000007;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) cout << #x << ": " << x << endl

template <typename T> class Treap {
public:
  Treap() : root_(nullptr) {}
  void Insert(int k, T v) { root_ = Insert(root_, k, v, rand()); }
  void Update(int k, T v) {
    root_ = Erase(root_, k);
    root_ = Insert(root_, k, v, rand());
  }
  void Shift(int l, int r) { root_ = Shift(root_, l, r + 1); }
  T Min(int l, int r) { return Min(root_, l, r + 1); }
  T Max(int l, int r) { return Max(root_, l, r + 1); }
  T Sum(int l, int r) { return Sum(root_, l, r + 1); }

private:
  static const T kInf = 10000001; // TODO

  struct Node {
    Node(int v, double p) : val(v), pri(p), cnt(1), sum(v), min(v), max(v) {
      lch = nullptr;
      rch = nullptr;
    }
    T val;
    Node *lch;
    Node *rch;
    double pri;
    int cnt;
    T sum;
    T min;
    T max;
  };

  int Count(Node *t) { return !t ? 0 : t->cnt; }
  int Sum(Node *t) { return !t ? 0 : t->sum; }
  int Min(Node *t) { return !t ? kInf : t->min; }
  int Max(Node *t) { return !t ? -kInf : t->max; }
  Node *Update(Node *t) {
    t->cnt = Count(t->lch) + Count(t->rch) + 1;
    t->sum = Sum(t->lch) + Sum(t->rch) + t->val;
    t->min = min(min(Min(t->lch), Min(t->rch)), t->val);
    t->max = max(max(Max(t->lch), Max(t->rch)), t->val);
    return t;
  }
  Node *Merge(Node *l, Node *r) {
    if (!l) {
      return r;
    } else if (!r) {
      return l;
    }

    if (l->pri > r->pri) {
      l->rch = Merge(l->rch, r);
      return Update(l);
    } else {
      r->lch = Merge(l, r->lch);
      return Update(r);
    }
  }
  pair<Node *, Node *> Split(Node *t, int k) { // [0, k), [k, n)
    if (!t)
      return make_pair(nullptr, nullptr);

    if (k <= Count(t->lch)) {
      auto s = Split(t->lch, k);
      t->lch = s.second;
      return make_pair(s.first, Update(t));
    } else {
      auto s = Split(t->rch, k - Count(t->lch) - 1);
      t->rch = s.first;
      return make_pair(Update(t), s.second);
    }
  }
  Node *Insert(Node *t, int k, int val, double pri) {
    auto s = Split(t, k);
    Node *n = new Node(val, pri);
    return Merge(Merge(s.first, n), s.second);
  }
  Node *Erase(Node *t, int k) {
    auto s = Split(t, k);
    auto u = Split(s.second, 1);
    delete u.first;
    return Merge(s.first, u.second);
  }
  Node *Shift(Node *t, int l, int r) {
    auto c = Split(t, r);
    auto b = Split(c.first, r - 1);
    auto a = Split(b.first, l);
    return Merge(Merge(a.first, b.second), Merge(a.second, c.second));
  }
  int Min(Node *t, int l, int r) {
    if (!t)
      return kInf;
    if (l <= 0 && Count(t) <= r)
      return Min(t);
    if (r <= 0 || Count(t) <= l)
      return kInf;
    int l_min = Min(t->lch, l, r);
    int r_min = Min(t->rch, l - Count(t->lch) - 1, r - Count(t->lch) - 1);
    int ans = min(l_min, r_min);
    if (l <= Count(t->lch) && Count(t->lch) < r) {
      ans = min(ans, t->val);
    }
    return ans;
  }
  int Max(Node *t, int l, int r) {
    if (!t)
      return -kInf;
    if (l <= 0 && Count(t) <= r)
      return Max(t);
    if (r <= 0 || Count(t) <= l)
      return -kInf;
    int l_max = Max(t->lch, l, r);
    int r_max = Max(t->rch, l - Count(t->lch) - 1, r - Count(t->lch) - 1);
    int ans = max(l_max, r_max);
    if (l <= Count(t->lch) && Count(t->lch) < r) {
      ans = max(ans, t->val);
    }
    return ans;
  }
  Node *root_;
};

int main() {
  int N;
  cin >> N;
  vector<array<int, 2>> wh(N);
  REP(i, N) {
    cin >> wh[i][0] >> wh[i][1];
    wh[i][1] *= -1;
  }
  sort(ALL(wh));
  Treap<int> treap;
  REP(i, 100001) {
    treap.Insert(i, 0);
  }
  REP(i, N) {
    int h = -wh[i][1];
    treap.Update(h, treap.Max(0, h - 1) + 1);
  }
  std::cout << treap.Max(0, 100001) << std::endl;
}
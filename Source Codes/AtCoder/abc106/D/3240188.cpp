#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <cstdio>
#include <unordered_map>
#include <map>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define llrep(i, a, b) for(ll i = (a); i < (b); ++i )
#define llrrep(i, a, b) for(ll i = (a); i > (b); --i )
#define llREP(i, a, b) for(ll i = (a); i <= (b); ++i )
#define llRREP(i, a, b) for(ll i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )

template<typename T=int>
class UnionFind {
 public:
  explicit UnionFind(unsigned long long n) : rank_(n, 0), p_(n, 0) {
    for (T i = 0; i < n; i++) {
      MakeSet(i);
    }
  }

  void MakeSet(T x) {
    p_[x] = x;
    rank_[x] = 0;
  }

  bool Same(T x, T y) {
    return FindSet(x) == FindSet(y);
  }

  void Link(T x, T y) {
    if (rank_[x] > rank_[y]) {
      p_[y] = x;
    } else {
      p_[x] = y;
      if (rank_[x] == rank_[y]) {
        rank_[y]++;
      }
    }
  }

  void Unite(T x, T y) {
    Link(FindSet(x), FindSet(y));
  }

  T FindSet(T x) {
    if (x != p_[x]) {
      p_[x] = FindSet(p_[x]);
    }
    return p_[x];
  }

 private:
  std::vector<T> rank_, p_;
};

template<typename NumT = ull, typename CostT = ull>
class Dijkstra {
 public:
  Dijkstra(unsigned long long num, CostT max_cost) :
      num_(num),
      max_cost_(max_cost),
      v_(num, std::vector<CostT>(num, max_cost)),
      c_(num, 0),
      d_(num, max_cost),
      p_(num, 0) {
  };

  void ComputeWithQ(NumT start) {
    d_[start] = 0;
    p_[start] = start;
    priority_queue<std::pair<CostT, NumT>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      auto ni = node.second;
      auto c = -node.first;
      c_[ni] = 1;
      if (d_[ni] < c) {
        continue;
      }
      d_[ni] = c;

      for (int i = 0; i < num_; i++) {
        if (v_[ni][i] == max_cost_) {
          continue;
        }
        if ((c_[i] != 1) && (d_[i] > (v_[ni][i] + d_[ni]))) {
          p_[i] = ni;
          d_[i] = v_[ni][i] + d_[ni];
          pq.push(make_pair(-d_[i], i));
        }
      }
    }
  }

  void Compute(int start) {
    d_[start] = 0;
    p_[start] = start;
    while (true) {
      int m = -1;
      int min_d = max_cost_;
      for (int i = 0; i < num_; i++) {
        if ((c_[i] == 0) && (min_d > d_[i])) {
          min_d = d_[i];
          m = i;
        }
      }
      if (m < 0) {
        break;
      }
      c_[m] = 1;
      for (int i = 0; i < num_; i++) {
        if ((c_[i] == 0) && (d_[i] > (d_[m] + v_[m][i]))) {
          d_[i] = d_[m] + v_[m][i];
          p_[i] = m;
        }
      }
    }
  }

  void Set(NumT s, NumT d, CostT c) {
    v_[s][d] = c;
  }

  CostT Distance(NumT d) {
    return d_[d];
  }

 public:
  NumT num_;
  CostT max_cost_;
  std::vector<std::vector<CostT>> v_;
  std::vector<int> c_;
  std::vector<int> d_;
  std::vector<NumT> p_;
};

int nibutan(int *ary, int ok, int ng) {
  bool is_valid;
  while (std::abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    // is_valid = check(mid);
    if (is_valid) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

template<typename NumT = int, typename CostT = unsigned long long>
class DijkstraQ {
 public:
  DijkstraQ(unsigned long long num, CostT max_cost) :
      adj_(num, std::vector<std::pair<NumT, CostT>>()),
      c_(num, 0), d_(num, max_cost) {}

  void Compute(NumT start) {
    std::priority_queue<std::pair<CostT, NumT>> q;
    d_[start] = 0;
    q.push(std::make_pair(0, start));

    while (!q.empty()) {
      std::pair<CostT, NumT> node = q.top();
      q.pop();
      auto n = node.second;
      auto c = -node.first;
      c_[n] = 1;
      if (c > d_[n]) {
        continue;
      }
      d_[n] = c;

      for (NumT i = 0; i < adj_[n].size(); i++) {
        auto nn = adj_[n][i].first;
        auto nc = adj_[n][i].second;
        if (c_[nn] > 0) {
          continue;
        }
        if (d_[nn] > (c + nc)) {
          d_[nn] = c + nc;
          q.push(std::make_pair(-d_[nn], nn));
        }
      }
    }
  }

  void Set(NumT s, NumT d, CostT c) {
    adj_[s].push_back(std::make_pair(d, c));
  }

  CostT Distance(NumT d) {
    return d_[d];
  }

  std::vector<CostT> d_;
  std::vector<int> c_;
  std::vector<std::vector<std::pair<NumT, CostT>>> adj_;
};

// x >= y
template<typename T>
inline T gcd(T x, T y) { return y ? gcd(y, x % y) : x; }

template<typename T>
inline T lcm(T x, T y) { return (x / gcd(x, y)) * y; }

// return gcd(a, b)
// x, y satisfy ax + by = gcd(a, b)
ll xgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = xgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

bool check(int *A, int i) {
  return A[i] < 39;
}

class D2Tree {

 public:
  struct node {
    int id, x, y;
  };

  struct tree {
    int location, l, r;
  };

  D2Tree(int n) : v_(n, {-1, -1, -1}), t_(n, {-1, -1, -1}), n_(n), np_(0) {
  }

  int MakeTree(int l, int r, int depth) {
    if (l >= r) {
      return -1;
    }

    int m = (l + r) / 2;
    int t = np_++;

    if (depth % 2 == 0) {
      sort(&v_[l], &v_[r], [&](auto &l, auto &r) { return l.x < r.x; });
    } else {
      sort(&v_[l], &v_[r], [&](auto &l, auto &r) { return l.y < r.y; });
    }

    t_[t].location = m;
    t_[t].l = MakeTree(l, m, depth + 1);
    t_[t].r = MakeTree(m + 1, r, depth + 1);
    return t;
  }

  void find(vector<int> &find_nodes, int ix, int sx, int tx, int sy, int ty, int depth) {
    int x = v_[t_[ix].location].x;
    int y = v_[t_[ix].location].y;
    if ((sx <= x) && (x <= tx) && (sy <= y) && (y <= ty)) {
      find_nodes.push_back(v_[t_[ix].location].id);
    }

    if (depth % 2 == 0) {
      if ((t_[ix].l != -1) && (sx <= x)) {
        find(find_nodes, t_[ix].l, sx, tx, sy, ty, depth + 1);
      }
      if ((t_[ix].r != -1) && (x <= tx)) {
        find(find_nodes, t_[ix].r, sx, tx, sy, ty, depth + 1);
      }
    } else {
      if ((t_[ix].l != -1) && (sy <= y)) {
        find(find_nodes, t_[ix].l, sx, tx, sy, ty, depth + 1);
      }
      if ((t_[ix].r != -1) && (y <= ty)) {
        find(find_nodes, t_[ix].r, sx, tx, sy, ty, depth + 1);
      }
    }
  }

  vector<node> v_;
  vector<tree> t_;
  int n_;
  int np_;
};

//struct SegmentTree {
//  int INF = numeric_limits<int>::max() / 2;
//  SegmentTree(vector<int> &V, unsigned long long n): N(n), T(2*n-1, -1) {
//    for (int i = 0; i < n; i++) {
//      T[i + 2 * N - 1] = V[i];
//    }
//    for (long long i = 2 * n - 2; i >=0; i--) {
//      T[i] = min(T[i * 2 + 1], T[i * 2 + 2]);
//    }
//  }
//
//  void Update(int k, int v) {
//    T[2 * N - 1 + k] = v;
//    while(k != 0) {
//      k /= 2;
//      int m = min(T[k * 2 + 1], T[k * 2 + 2]);
//      if (m == T[k]) {
//        break;
//      }
//      T[k] = m;
//    }
//  }
//
//  int GetMin(int tgt_l, int tgt_r, int k = 0, int cov_l=0, int cov_r=-1) {
//    if (cov_r == -1) cov_r = N;
//
//    if (tgt_r <= cov_l || cov_r <= tgt_l) {
//      return INF;
//    }
//    if (tgt_l <= cov_l && cov_r <= tgt_r) {
//      return T[k];
//    }
//
//    int m = (cov_l + cov_r) / 2;
//    int vl = GetMin(tgt_l, tgt_r, k * 2 + 1, cov_l, m);
//    int vr = GetMin(tgt_l, tgt_r, k * 2 + 2, m, cov_r);
//    return min(vl, vr);
//  }
//
//
//  unsigned long long N;
//  vector<int> T;
//};



template<typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

ll ExtGcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ExtGcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

ll calc_mod(long long a, long long m) {
  return (a % m + m) % m;
}

ll calc_modinv(ll a, ll m) {
  ll x, y;
  ExtGcd(a, m, x, y);
  return calc_mod(x, m);
}

void calc_modinv_ary(ll *mod_inv, ll m, ll n) {
  mod_inv[1] = 1;
  rep(i, 2, n + 1) {
    mod_inv[i] = (mod_inv[m % i] * (m - m / i) % m) % m;
  }
}

//ll A[1000];

//ll P[20100];
//ll MOD = 998244353;
//ll POW2[20100];
//ll FAC[20100];
//ll FACINV[20100];
//ll INV[20100];
//
//void COMInit() {
//  FAC[0] = FAC[1] = 1;
//  FACINV[0] = FACINV[1] = 1;
//  INV[1] = 1;
//  rep(i, 2, 20100) {
//    FAC[i] = FAC[i - 1] * i % MOD;
//    INV[i] = INV[MOD % i] * (MOD - MOD / i) % MOD;
//    FACINV[i] = FACINV[i - 1] * INV[i] % MOD;
//  }
//}
//
//ll COM(ll n, ll k) {
//  if (n < k) return 0;
//  if (n < 0 || k < 0) return 0;
//  return FAC[n] * (FACINV[n - k] * FACINV[k] % MOD) % MOD;
//}


int N, M, Q;
int L[200010];
int R[200010];
int imos[600][600];

int main() {
  cin >> N >> M >> Q;
  rep(i, 0, M) {
    int l, r;
    cin >> l >> r;
    imos[l][r]++;
  }
  rep(l, 0, N) {
    rep(r, 0, N) {
      imos[l+1][r+1] += imos[l+1][r];
    }
  }
  rep(r, 0, N) {
    rep(l, 0, N) {
      imos[l+1][r+1] += imos[l][r+1];
    }
  }
  rep(i, 0, Q) {
    int l, r;
    cin >> l >> r;
    cout << imos[r][r] - imos[r][l-1] - imos[l-1][r] + imos[l-1][l-1] << endl;
  }
}
#include <cstdio>
#include <vector>
#include <algorithm>

template <typename M>
class SegTree {
  using T = typename M::element_type;
  std::vector<T> tree;
  const int n;

  public:

  SegTree(const std::vector<T> &a) : n(a.size()-1 ? 1 << (32 - __builtin_clz(a.size()-1)) : 1) {
    int n0 = a.size();
    tree.reserve(2*n);
    for(int i = 0; i < n0; ++i)  tree[i+n] = a[i];
    for(int i = n0; i < n; ++i)  tree[i+n] = M::id;
    for(int i = n-1; i > 0; --i) tree[i] = M::op(tree[2*i], tree[2*i|1]);
  }

  T query(int l, int r){
    T v = M::id;
    for(int t = r - l; t >= 1; t = r - l){
      int x = l | ((1U << 31) >>  __builtin_clz(t));
      int u = x & (-x);
      int k = __builtin_ctz(x);
      v = M::op(v, tree[(n|l) >> k]);
      l += u;
    }
    return v;
  }

  void update(int i, T x){
    int k = i+n;
    tree[k] = x;
    for(k = k >> 1; k > 0; k >>= 1){
      tree[k] = M::op(tree[2*k], tree[2*k|1]);
    }
  }
};

struct doubleAffineMonoid {
    using element_type = std::pair<double, double>;
    static element_type op(element_type const& x, element_type const& y) {
      return element_type(x.first * y.first, y.first * x.second + y.second);
    }
    static const element_type id;
};
const doubleAffineMonoid::element_type doubleAffineMonoid::id = doubleAffineMonoid::element_type(1.0, 0.0);
 
using Monoid = doubleAffineMonoid;

struct Q {
  int i;
  long long int p;
  double a;
  double b;
  Q(int i, long long int p, double a, double b):i(i),p(p),a(a),b(b) {}
};

bool compp(const Q &l, const Q &r){
  return l.p < r.p;
}
bool compi(const Q &l, const Q &r){
  return l.i < r.i;
}

std::vector<Q> queries;

int main(){
  long long int n;
  int m;
  std::scanf("%lld%d", &n, &m);
  queries.reserve(m);
  for(int i=0;i<m;i++){
    long long int p;
    double a, b;
    std::scanf("%lld%lf%lf", &p, &a, &b);
    queries.emplace_back(Q(i,p,a,b));
  }

  std::sort(queries.begin(), queries.end(), compp);
  long long int tmp = -1;
  int idx = -1;
  for(int i=0;i<m;i++){
    if(queries[i].p != tmp){
      tmp = queries[i].p;
      ++idx;
    }
    queries[i].p=idx;
  }
  std::sort(queries.begin(), queries.end(), compi);
  
  std::vector<Monoid::element_type> vec(m, Monoid::id);
  SegTree<Monoid> segtree(vec);

  double vmax, vmin;
  vmax = vmin = 1.0;
  for(int i=0;i<m;i++){
    segtree.update(queries[i].p, Monoid::element_type(queries[i].a, queries[i].b));
    Monoid::element_type x = segtree.query(0, m);
    double v = x.first + x.second;
    vmax = std::max(vmax, v);
    vmin = std::min(vmin, v);
  }

  std::printf("%lf\n%lf\n", vmin, vmax);
  return 0;
}
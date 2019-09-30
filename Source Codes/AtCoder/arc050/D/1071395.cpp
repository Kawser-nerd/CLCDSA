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

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

template <typename T, const T& merge(const T&, const T&)>
class SegmentTree {
  const int n;
  const T id;
  vector<T> data;
  T sub(int l, int r, int node, int lb, int ub) const {
    if (ub <= l || r <= lb) return id;
    if (l <= lb && ub <= r) return data[node];
    T vl = sub(l, r, node * 2 + 0, lb, (lb + ub) / 2);
    T vr = sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
    return merge(vl, vr);
  }
  int size(int n) const {
    return n == 1 ? n : size((n + 1) / 2) * 2;
  }
public:
  SegmentTree(int m, T id) : n(size(m)), id(id), data(n * 2, id) {}
  void update(int p, T val) {
    assert (0 <= p && p < n);
    p += n;
    data[p] = val;
    while (p /= 2) {
      int l = p * 2, r = p * 2 + 1;
      data[p] = merge(data[l], data[r]);
    }
  }
  T find(int l, int r) const {
    return sub(l, r, 1, 0, n);
  }
};

struct SuffixArray {
  struct SAComp {
    const int h;
    const vector<int> &g;
    SAComp(int h, vector<int> &g) : h(h), g(g) {;}
    bool operator() (int a, int b) {
      return a != b && (g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h]);
    }
  };

  int n;
  char *str;
  vector<int> sa, lcp;

  SuffixArray(const string &t) : n(t.size()), sa(n+1), lcp(n+1) {
    str = new char[n+1];
    strcpy(str, t.c_str());

    // build SA
    vector<int> g(n+1, 0), b(n+1, 0);
    for (int i = 0; i <= n; ++i) { sa[i] = i; g[i] = str[i]; }
    sort(begin(sa), end(sa), SAComp(0, g));
    for (int h = 1; b[n] != n; h *= 2) {
      SAComp comp(h, g);
      sort(sa.begin(), sa.end(), comp);
      for (int i = 0; i < n; ++i)
        b[i+1] = b[i] + comp(sa[i], sa[i+1]);
      for (int i = 0; i <= n; ++i)
        g[sa[i]] = b[i];
    }

    // build LCP
    int h = 0;
    for (int i = 0; i <= n; ++i) b[sa[i]] = i;
    for (int i = 0; i <= n; ++i) {
      if (b[i]) {
        for (int j = sa[b[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; ++h);
        lcp[b[i]] = h;
      }
      else {
        lcp[b[i]] = -1;
      }
      if (h > 0) --h;
    }
  }
  ~SuffixArray() { delete []str; }

  int find(string t) {
    int m = t.size();
    char p[m+1];
    strcpy(p, t.c_str());
    int left = -1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (strncmp(str + sa[mid], p, m) < 0) left = mid;
      else right = mid;
    }
    return strncmp(str + sa[right], p, m) == 0 ? sa[right] : -1;
  }
};

class LCP {
public:
  int n;
  vector<int> mapsto;
  SegmentTree<int,min> seg;
  LCP(const string &str) : n(str.size()), mapsto(n), seg(n, int(1e9)) {
    SuffixArray sa(str);
    for (int i = 0; i < n; ++i) mapsto[sa.sa[i+1]] = i;
    for (int i = 0; i < n-1; ++i) seg.update(i, sa.lcp[i+2]);
  }
  int query(int i, int j) const {
    if (i == j) return n - i;
    i = mapsto[i]; j = mapsto[j];
    return seg.find(min(i, j), max(i, j));
  }
};

struct VecComp {
  const LCP lcp;
  VecComp(LCP lcp) : lcp(lcp) {}
  bool operator() (int i, int j) const {
    const int n = lcp.n;
    int l = min(i, j), r = max(i, j);
    if (lcp.query(i, j) != n - r) {
      return lcp.mapsto[i] < lcp.mapsto[j];
    }
    i += n - r; j += n - r;
    if (i == n) i = l;
    if (j == n) j = l;
    if (lcp.query(i, j) < r - l) {
      return lcp.mapsto[i] < lcp.mapsto[j];
    }
    i += r - l; j += r - l;
    if (i == n) i = r;
    if (j == n) j = r;
    return lcp.mapsto[i] < lcp.mapsto[j];
  }
};

void solve(ll N, const string &S){
  LCP lcp(S);
  VecComp comp(lcp);
  vector<int> vec(N);
  iota(ALL(vec), 0);
  sort(ALL(vec), comp);
  for (int i: vec) cout << i + 1 << endl;
}

int main(){	
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	string S;
	scanf("%lld", &N);
	cin >> S;
	solve(N, S);
	return 0;
}
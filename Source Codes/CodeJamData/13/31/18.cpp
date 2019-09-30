#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stdint.h>

typedef int64_t ll;

using namespace std;

bool is_good(char c) {
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 0;
  else
    return 1;
}

class SegmentTree {
  vector < int > values, pushs;
  int n;

private:
  inline int middle(int l, int r) { return (l + r) >> 1; }
  inline int left(int v) { return (v << 1); }
  inline int right(int v) { return (v << 1) | 1; }

public:
  SegmentTree(const vector < int > & init_values) :
    n(init_values.size())
  {
    values.resize(4 * n);
    pushs.assign(4 * n, 0);
    build(1, 0, n - 1, init_values);
  }

  void build(int v, int l, int r, const vector < int > & init_values) {
    if(l == r) {
      values[v] = init_values[l];
    } else {
      int m = middle(l, r);
      build(left(v), l, m, init_values);
      build(right(v), m + 1, r, init_values);
      values[v] = max(values[left(v)], values[right(v)]);
    }
  }

  void do_push(int v) {
    if(pushs[v] != 0) {
      pushs[left(v)] += pushs[v];
      pushs[right(v)] += pushs[v];
      values[left(v)] += pushs[v];
      values[right(v)] += pushs[v];
      pushs[v] = 0;
    }
  }

  int query_max(int v, int l, int r, int tl, int tr) {
    if(tl > tr)
      throw 42;

    if(l == tl && r == tr)
      return values[v];

    int m = middle(l, r);

    do_push(v);

    int res = 0;

    if(tl <= m)
      res = query_max(left(v), l, m, tl, min(tr, m));

    if(tr > m)
      res = max(res, query_max(right(v), m + 1, r, max(m + 1, tl), tr));

    return res;
  }

  void query_change(int v, int l, int r, int tl, int tr, int diff) {
    if(l == tl && r == tr) {
      values[v] += diff;
      pushs[v] += diff;

      return;
    }

    int m = middle(l, r);

    do_push(v);

    if(tl <= m)
      query_change(left(v), l, m, tl, min(tr, m), diff);

    if(tr > m)
      query_change(right(v), m + 1, r, max(m + 1, tl), tr, diff);

    values[v] = max(values[left(v)], values[right(v)]);
  }
};

ll solve() {
  string s;
  ll k;
  cin >> s >> k;
  int n = int(s.size());

  vector < int > values(n), block_ends(n);

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(is_good(s[i]))
      ++cnt;
    else
      cnt = 0;

    values[i] = cnt;
  }

  int ptr = -1;
  for(int i = n - 1; i >= 0; i--) {
    if(is_good(s[i])) {
      if(ptr == -1)
        ptr = i;
    } else {
      ptr = -1;
    }

    block_ends[i] = ptr;
  }

  SegmentTree st(values);

  ll res = 0;

  for(int i = 0; i < n; i++) {
    int l = i - 1, r = n;

    while(r - l > 1) {
      int m = (l + r) / 2;
      int value = st.query_max(1, 0, n - 1, i, m);

      if(value >= k) {
        r = m;
      } else {
        l = m;
      }
    }

    //cerr << "debug: " << i << " " << r << endl;

    res += (n - r);

    if(block_ends[i] != -1) {
      st.query_change(1, 0, n - 1, i, block_ends[i], -1);
    }
  }

  return res;
}

int main() {
  int tests;
  cin >> tests;

  for(int i = 1; i <= tests; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }

  return 0;
}
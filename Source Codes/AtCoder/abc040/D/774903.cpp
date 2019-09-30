#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>

using namespace std;

const int N = 100000;
const int M = 200000;
const int Q = 100000;

int parent(int x, int p[]) {
  if (p[x] != x) {
    p[x] = parent(p[x], p);
  }
  return p[x];
}

int main() {
  int n, m, q;
  int a[M], b[M], y[M], v[Q], w[Q], ans[Q], idx_m[M], idx_q[Q], p[N], c[N];
  int pos = 0;
  scanf("%d%d", &n, &m);
  for (int mi = 0; mi < m; ++mi) {
    scanf("%d%d%d", &a[mi], &b[mi], &y[mi]);
  }
  scanf("%d", &q);
  for (int qi = 0; qi < q; ++qi) {
    scanf("%d%d", &v[qi], &w[qi]);
  }
  iota(idx_m, idx_m + m, 0);
  sort(idx_m, idx_m + m, [&](int i, int j) {return y[i] > y[j];});
  iota(idx_q, idx_q + q, 0);
  sort(idx_q, idx_q + q, [&](int i, int j) {return w[i] > w[j];});
  iota(p, p + n, 0);
  fill(c, c + n, 1);
  for (int i = 0; i < q; ++i) {
    int qi = idx_q[i];
    while (pos < m and w[qi] < y[idx_m[pos]]) {
      int px = parent(a[idx_m[pos]] - 1, p);
      int py = parent(b[idx_m[pos]] - 1, p);
      if (px != py) {
        if (c[px] > c[py]) {
          swap(px, py);
        }
        p[px] = py;
        c[py] += c[px];
      }
      ++pos;
    }
    ans[qi] = c[parent(v[qi] - 1, p)];
  }
  for (int qi = 0; qi < q; ++qi) {
    printf("%d\n", ans[qi]);
  }
  return 0;
}
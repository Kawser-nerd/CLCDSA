#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e6;
const int N = 400010;

int fin;
int ss[N], ff[N], c[N], f[N], obr[N], pred[N], last[N], st[N], edge[N];
int cost[N];
int m;

void add(int x, int y, int z, int xx, int yy) {
  m++;
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  obr[m] = yy;
}

int x[N], d[N];

bool expath() {
  for (int i = 0; i <= fin; i++) d[i] = -1;
  int b = 1, e = 1;
  x[1] = 0;
  d[0] = 0;
  while (b <= e) {
    int j = last[x[b]];
    while (j > 0) {
      if (c[j] > f[j] && d[ff[j]] == -1) {
        e++;
        x[e] = ff[j];
        d[x[e]] = d[x[b]] + 1;
        if (x[e] == fin) {
          return true;
        }
      }
      j = pred[j];
    }
    b++;
  }
  return false;
}

int rec(int v, int w) {
  if (v == fin) {
    return w;
  }
  int r = 0, j = last[v];
  while (j > 0) {
    last[v] = pred[j];
    if (c[j] > f[j] && d[ff[j]] == d[v] + 1) {
      int ww = c[j] - f[j];
      if (w - r < ww) ww = w - r;
      int t = rec(ff[j], ww);
      if (t > 0) {
        f[j] += t;
        if (obr[j] != 0) f[obr[j]] -= t;
        r += t;
        if (r == w) break;
      }
    }
    j = pred[j];
  }
  return r;
}

int g[777][777];
int ex[N], ey[N];

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    int nn, mm, kk;
    scanf("%d %d %d", &nn, &mm, &kk);
    for (int i = 0; i < mm; i++) {
      scanf("%d %d", ex + i, ey + i);
      ex[i + mm] = ey[i];
      ey[i + mm] = ex[i];
    }
    mm += mm;
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    for (int i = 0; i < nn; i++) {
      cost[i] = 0;
    }
    for (int i = 0; i < nn; i++) {
      for (int j = 0; j < nn; j++) {
        g[i][j] = (i == j ? 0 : inf);
      }
    }
    for (int i = 0; i < mm; i++) {
      g[ex[i]][ey[i]] = 1 + cost[ex[i]];
      g[ey[i]][ex[i]] = 1 + cost[ey[i]];
    }
    for (int k = 0; k < nn; k++) {
      for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    int ans = g[0][nn - 1];
    cost[0] = 1;
    int flow = 1;
    while (flow <= kk) {
    ans++;
    for (int i = 0; i < nn; i++) {
      for (int j = 0; j < nn; j++) {
        g[i][j] = (i == j ? 0 : inf);
      }
    }
    for (int i = 0; i < mm; i++) {
      g[ex[i]][ey[i]] = 1 + cost[ex[i]];
      g[ey[i]][ex[i]] = 1 + cost[ey[i]];
    }
    for (int k = 0; k < nn; k++) {
      for (int i = 0; i < nn; i++) {
        for (int j = 0; j < nn; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    fin = 2 * nn - 3;
    m = 0;
    for (int i = 0; i < mm; i++) {
      if (g[0][ex[i]] + cost[ex[i]] + 1 + g[ey[i]][nn - 1] == g[0][nn - 1]) {
        add(2 * ex[i], 2 * ey[i] - 1, inf, 0, m + 2);
        add(2 * ey[i] - 1, 2 * ex[i], 0, 0, m);
      }
    }
    for (int i = 1; i < nn - 1; i++) {
      add(2 * i - 1, 2 * i, (cost[i] == 1 ? inf : 1), 0, m + 2);
      add(2 * i, 2 * i - 1, 0, 0, m);
    }
    for (int i = 0; i <= fin; i++) {
      last[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      pred[i] = last[ss[i]];
      last[ss[i]] = i;
    }
    for (int i = 0; i <= fin; i++) {
      st[i] = last[i];
    }
      while (expath()) {
        int t = rec(0, inf);
        flow += t;
        for (int i = 0; i <= fin; i++) {
          last[i] = st[i];
        }
      }
      for (int i = 1; i < nn - 1; i++) {
        if (d[2 * i - 1] != -1 && d[2 * i] == -1) {
          cost[i] = 1;
        }
      }
//    cerr << "flow = " << ans << ", k = " << kk << endl;
//cerr << "now flow = " << flow << endl;
}
    printf("%d\n", ans);
/*    if (add > 2) {
      printf("bad :(\n");
      if (nn < 50) {
        printf("%d %d %d\n", nn, mm / 2, kk);
        for (int i = 0; i < mm / 2; i++) printf("%d %d\n", ex[i], ey[i]);
      }
    }*/
    // solution ends
    fflush(stdout);
//    fprintf(stderr, "test %d solved, time = %d ms\n", qq, (int)clock());
  }
  return 0;
}

#include <cassert>
#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n, m;
    assert (scanf ("%d%d", &n, &m) == 2);
    int grid_na[n][n], orig_na[n][n], sum_nai[n], sum_nao[n];
    int grid_nb[n][n], orig_nb[n][n], sum_nbi[2 * n - 1], sum_nbo[2 * n - 1];
    memset (grid_na, 0, sizeof (grid_na[0][0]) * n * n);
    memset (grid_nb, 0, sizeof (grid_nb[0][0]) * n * n);
    memset (sum_nai, 0, sizeof (sum_nai[0]) * n);
    memset (sum_nao, 0, sizeof (sum_nao[0]) * n);
    memset (sum_nbi, 0, sizeof (sum_nbi[0]) * (2 * n - 1));
    memset (sum_nbo, 0, sizeof (sum_nbo[0]) * (2 * n - 1));
    int ans = 0;
    for (int i = 0; i < m; i++) {
      char c;
      int x, y;
      assert (scanf (" %c%d%d", &c, &x, &y) == 3);
      x--, y--;
      if (c == 'o' || c == 'x') {
        grid_na[x][y] = 1;
        sum_nai[x]++;
        sum_nao[y]++;
        ans++;
      }
      if (c == 'o' || c == '+') {
        grid_nb[x][y] = 1;
        sum_nbi[x + y]++;
        sum_nbo[x + n - 1 - y]++;
        ans++;
      }
    }
    memcpy (orig_na, grid_na, sizeof (grid_na[0][0]) * n * n);
    memcpy (orig_nb, grid_nb, sizeof (grid_nb[0][0]) * n * n);
    int gn = 0;
    int gs = gn++, gt = gn++;
    int gai[n], gao[n];
    for (int i = 0; i < n; i++) {
      gai[i] = gn++, gao[i] = gn++;
    }
    int gbi[2 * n - 1], gbo[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++) {
      gbi[i] = gn++, gbo[i] = gn++;
    }
    vector <int> gu[gn], gr[gn], gf[gn], gc[gn];
    vector <int*> gx[gn];
    auto edge = [&gu, &gr, &gf, &gc, &gx]( int a, int b, int f, bool force, int *magic ) {
      // fprintf (stderr, " edge (%d) -> (%d)\n", a, b);
      int ra = (int)gu[a].size (), rb = (int)gu[b].size ();
      if (magic)
        assert (f == *magic);
      gu[a].push_back (b);
      gr[a].push_back (rb);
      gf[a].push_back (f);
      gc[a].push_back (1);
      gx[a].push_back (magic);
      gu[b].push_back (a);
      gr[b].push_back (ra);
      gf[b].push_back (-f);
      gc[b].push_back (force ? -f : 0);
      gx[b].push_back (0);
    };
    for (int i = 0; i < n; i++) {
      assert (sum_nai[i] <= 1);
      assert (sum_nao[i] <= 1);
      edge (gs, gai[i], sum_nai[i], false, 0);
      edge (gao[i], gt, sum_nao[i], false, 0);
    }
    // fprintf (stderr, "!!\n");
    for (int i = 0; i < 2 * n - 1; i++) {
      assert (sum_nbi[i] <= 1);
      assert (sum_nbo[i] <= 1);
      edge (gs, gbi[i], sum_nbi[i], false, 0);
      edge (gbo[i], gt, sum_nbo[i], false, 0);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        edge (gai[i], gao[j], grid_na[i][j], grid_na[i][j], &grid_na[i][j]);
        edge (gbi[i + j], gbo[i + n - 1 - j], grid_nb[i][j], grid_nb[i][j], &grid_nb[i][j]);
      }
    for (int i = 0; i < gn; i++) {
      int sf = 0;
      for (int j = 0; j < (int)gu[i].size (); j++) {
        assert (gf[i][j] <= gc[i][j]);
        assert (j == gr[gu[i][j]][gr[i][j]]);
        sf += gf[i][j];
      }
      assert (i == gs || i == gt || sf == 0);
    }
    // MaxFlow
    while (true) {
      int c[gn];
      memset (c, 0, sizeof (c[0]) * gn);
      auto dfs = [&c, &gt, &gu, &gr, &gf, &gc, &gx]( auto &dfs, int v ) {
        if (v == gt)
          return true;
        c[v] = 1;
        for (int i = 0; i < (int)gu[v].size (); i++) {
          if (gf[v][i] >= gc[v][i])
            continue;
          if (c[gu[v][i]])
            continue;
          if (!dfs (dfs, gu[v][i]))
            continue;
          gf[v][i]++;
          if (gx[v][i])
            *gx[v][i] = gf[v][i];
          gf[gu[v][i]][gr[v][i]]--;
          if (gx[gu[v][i]][gr[v][i]])
            *gx[gu[v][i]][gr[v][i]] = gf[gu[v][i]][gr[v][i]];
          return true;
        }
        return false;
      };
      if (!dfs (dfs, gs)) {
        break;
      }
      ans++;
    }
    int m_new = 0, res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        res += (!!grid_na[i][j]) + (!!grid_nb[i][j]);
        assert (grid_na[i][j] >= orig_na[i][j]);
        assert (grid_nb[i][j] >= orig_nb[i][j]);
        if (grid_na[i][j] == orig_na[i][j] && grid_nb[i][j] == orig_nb[i][j])
          continue;
        m_new++;
      }
    // fprintf (stderr, "ans = %d, res = %d\n", ans, res);
    assert (ans == res);
    printf ("Case #%d: %d %d\n", tt, ans, m_new);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (grid_na[i][j] == orig_na[i][j] && grid_nb[i][j] == orig_nb[i][j])
          continue;
        char value[5] = ".+xo";
        printf ("%c %d %d\n", value[grid_na[i][j] * 2 + grid_nb[i][j]], i + 1, j + 1);
      }
  }
  return 0;
}


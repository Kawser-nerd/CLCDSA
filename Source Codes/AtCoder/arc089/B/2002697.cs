using System;

class Solver {
  public void solve() {
    var buf = Console.ReadLine().Split();
    int n = int.Parse(buf[0]);
    int k = int.Parse(buf[1]);
    int m = k * 2;
    int[,,] a = new int[2, m + 1, m + 1];
    for (int i = 0; i < n; i++) {
      buf = Console.ReadLine().Split();
      int x = int.Parse(buf[0]);
      int y = int.Parse(buf[1]);
      int c = buf[2]=="B" ? 1 : 0;
      x %= m; y %= m;
      a[c,x,y]++;
    }
    for (int c = 0; c < 2; c++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j <= m; j++) {
          a[c, i + 1, j] += a[c, i, j];
        }
      }
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j < m; j++) {
          a[c, i, j + 1] += a[c, i, j];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        for (int c = 0; c < 2; c++) {
          int cur = 0;
          int ti = i + k, tj = j + k;
          for (int nc = 0; nc < 2; nc++) {
            int tmp = 0;
            tmp += a[nc, m, tj] - a[nc, m, j];
            tmp += a[nc, ti, m] - a[nc, i, m];
            tmp -= (a[nc, ti, tj] - a[nc, ti, j] - a[nc, i, tj] + a[nc, i, j]) * 2;
            if (c != nc) tmp = a[nc, m, m] - tmp;
            cur += tmp;
          }
          ans = Math.Max(ans, cur);
        }
      }
    }
    Console.WriteLine(ans);
  }
}

/* Main */
class ReSha {
  static void Main() {
    new Solver().solve();
  }
}
using System;

class Solver {
  public void solve() {
    var buf = Console.ReadLine().Split();
    int na = int.Parse(buf[0]);
    int nb = int.Parse(buf[1]);
    int[,] d = new int[na, nb];
    for (int i = 0; i < na; i++) {
      buf = Console.ReadLine().Split();
      for (int j = 0; j < nb; j++) {
        d[i, j] = int.Parse(buf[j]);
      }
    }
    int m = 100;
    int n = 2 + m + m;
    int[,] c = new int[m + 1, m + 1];
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
        int cost = 0;
        for (int a = 1; a <= na; a++) {
          for (int b = 1; b <= nb; b++) {
            int nd = d[a - 1, b - 1];
            int bs = a * i + b * j;
            cost = Math.Max(cost, nd - bs);
          }
        }
        c[i, j] = cost;
      }
    }
    for (int a = 1; a <= na; a++) {
      for (int b = 1; b <= nb; b++) {
        int nd = d[a - 1, b - 1];
        bool ok = false;
        for (int i = 0; i <= m; i++) {
          for (int j = 0; j <= m; j++) {
            int cur = a * i + b * j + c[i, j];
            if (cur == nd) ok = true;
          }
        }
        if (!ok) {
          Console.WriteLine("Impossible");
          return;
        }
      }
    }
    Console.WriteLine("Possible");
    int es = m * 2 + (m + 1) * (m + 1);
    Console.WriteLine(n + " " + es);
    {
      int pv = 1;
      for (int i = 0; i < m; i++) {
        int nv = i + 2;
        Console.WriteLine(pv + " " + nv + " X");
        pv = nv;
      }
    }
    {
      int pv = n;
      for (int i = 0; i < m; i++) {
        int nv = n - i - 1;
        Console.WriteLine(nv + " " + pv + " Y");
        pv = nv;
      }
    }
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
        int u = i+1, v = n-j;
        Console.WriteLine(u + " " + v + " " + c[i, j]);
      }
    }
    Console.WriteLine(1 + " " + n);
  }
}

/* Main */
class ReSha {
  static void Main() {
    new Solver().solve();
  }
}
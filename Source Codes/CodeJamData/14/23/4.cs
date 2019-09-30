using System;
using System.IO;

class MainClass
{
  StreamReader inf;
  StreamWriter ouf;

  void solve()
  {
    var parts = inf.ReadLine().Split();
    int n = int.Parse(parts[0]);
    int m = int.Parse(parts[1]);

    var s = new string[n];
    for (int i = 0; i < n; ++i)
      s[i] = inf.ReadLine();
    var a = new bool[n, n];
    for (int i = 0; i < m; ++i) {
      var z = inf.ReadLine().Split();
      int u = int.Parse(z[0]) - 1;
      int v = int.Parse(z[1]) - 1;
      a[u, v] = true;
      a[v, u] = true;
    }

    string best = "";

    var p = new int[n];
    for (int i = 0; i < n; ++i)
      p[i] = i;
    var q = new int[n];

    while (true) {
      int h = 0;
      string r = s[p[0]];
      bool flag = true;
      q[h] = p[0];
      for (int i = 1; i < n; ++i) {
        while (h >= 0 && a[q[h], p[i]] == false)
          --h;
        if (h < 0) {
          flag = false;
          break;
        }
        q[++h] = p[i];
        r += s[p[i]];
      }

      if (flag && (best == "" || r.CompareTo(best) < 0))
        best = r;
    
      int k = n - 2;
      while (k >= 0 && p[k] > p[k + 1])
        --k;
      if (k < 0)
        break;
      int j = k + 1;
      while (j < n && p[j] > p[k])
        ++j;
      --j;
      int z;
      z = p[k];
      p[k] = p[j];
      p[j] = z;
      for (k = k + 1, j = n - 1; k < j; ++k, --j) {
        z = p[k];
        p[k] = p[j];
        p[j] = z;
      }
    }
    ouf.WriteLine(best);
  }

  void run()
  {
    inf = File.OpenText("c.in");
    ouf = File.CreateText("c.out");
    
    int tests = int.Parse(inf.ReadLine());
    for (int t = 1; t <= tests; ++t) {
      ouf.Write(String.Format("Case #{0}: ", t));
      solve();
    }

    inf.Close();
    ouf.Close();
  }

  public static void Main(string[] args)
  {
    new MainClass().run();
  }
}
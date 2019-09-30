using System;
using System.IO;

class MainClass
{
  StreamReader inf;
  StreamWriter ouf;

  void solve()
  {
    int n = int.Parse(inf.ReadLine());
    var s = new string[n];
    for (int i = 0; i < n; ++i)
      s[i] = inf.ReadLine();
    var p = new int[n];
    var a = new int[n];

    for (int i = 0; i < n; ++i)
      p[i] = 0;


    int score = 0;
    while (p[0] < s[0].Length) {
      char c = s[0][p[0]];
      for (int i = 0; i < n; ++i) {
        a[i] = 0;
        for (; p[i] < s[i].Length && s[i][p[i]] == c; ++p[i])
          ++a[i];
        if (a[i] == 0) {
          ouf.WriteLine("Fegla Won");
          return;
        }
      }

      int best = -1;
      for (int i = 0; i < n; ++i) {
        int r = 0;
        for (int j = 0; j < n; ++j)
          if (a[j] <= a[i])
            r += a[i] - a[j];
          else
            r += a[j] - a[i];
        if (best == -1 || r < best)
          best = r;
      }
      score += best;
    }

    for (int i = 1; i < n; ++i)
      if (p[i] < s[i].Length) {
        ouf.WriteLine("Fegla Won");
        return;
      }

    ouf.WriteLine(score);
  }

  void run()
  {
    inf = File.OpenText("a.in");
    ouf = File.CreateText("a.out");
    
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
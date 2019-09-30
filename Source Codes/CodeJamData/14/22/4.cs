using System;
using System.IO;

class MainClass
{
  StreamReader inf;
  StreamWriter ouf;
  int A, B, K;
  long score;
  long[,,,] mem = new long[31,2,2,2];

  void calc(int i, bool la, bool lb, bool lk)
  {
    //Console.WriteLine(String.Format("{0} {1} {2} {3}", i, la, lb, lk));
    if (la && lb && lk) {
      long r = 1 << (i + 1);
      score += r * r;
      return;
    }
    if (i == -1)
      return;
    int ia = la ? 1 : 0;
    int ib = lb ? 1 : 0;
    int ik = lk ? 1 : 0;
    if (mem[i, ia, ib, ik] != -1) {
      score += mem[i, ia, ib, ik];
      return;
    }

    long save = score;

    int x = (A >> i) & 1;
    int y = (B >> i) & 1;
    int z = (K >> i) & 1;

    int ka = 1;
    if (la || x == 1)
      ka = 2;
    int kb = 1;
    if (lb || y == 1)
      kb = 2;
    for (int q = 0; q < ka; ++q)
      for (int w = 0; w < kb; ++w)
        if (lk || (q & w) <= z) {
          calc(i - 1, la || q < x, lb || w < y, lk || (q & w) < z);
        }
    mem[i, ia, ib, ik] = score - save;
  }

  void solve()
  {
    var parts = inf.ReadLine().Split();
    A = int.Parse(parts[0]);
    B = int.Parse(parts[1]);
    K = int.Parse(parts[2]);
    score = 0;
    for (int i = 0; i <= 30; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          for (int t = 0; t < 2; ++t)
            mem[i, j, k, t] = -1;
    calc(30, false, false, false);
    ouf.WriteLine(score);
  }

  void run()
  {
    inf = File.OpenText("b.in");
    ouf = File.CreateText("b.out");
    
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
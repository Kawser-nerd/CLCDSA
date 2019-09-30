using System;

class Solver {
  public void solve() {
    int n = int.Parse(Console.ReadLine());
    int pt = 0, px = 0, py = 0;
    for (int i = 0; i < n; i++) {
      var buf = Console.ReadLine().Split();
      int t = int.Parse(buf[0]);
      int x = int.Parse(buf[1]);
      int y = int.Parse(buf[2]);
      int dt = t - pt;
      int dx = x - px;
      int dy = y - py;
      int dist = Math.Abs(dx) + Math.Abs(dy);
      if (dist > dt) {
        Console.WriteLine("No");
        return;
      }
      if (dist%2 != dt%2) {
        Console.WriteLine("No");
        return;
      }
      pt = t; px = x; py = y;
    }
    Console.WriteLine("Yes");
  }
}

/* Main */
class ReSha {
  static void Main() {
    new Solver().solve();
  }
}
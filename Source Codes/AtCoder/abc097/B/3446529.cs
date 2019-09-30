using System;

class Program {
  static void Main() {
    int x = int.Parse(Console.ReadLine());
    int ans = 1;
    for (int b = 2; b * b <= x; b++) {
      for (int p = 2; ; p++) {
        int t = (int)Math.Pow(b, p);
        if (t <= x) ans = Math.Max(ans, t);
        else break;
      }
    }
    Console.WriteLine(ans);
  }
}
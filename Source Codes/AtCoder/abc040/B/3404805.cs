using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int a = int.MaxValue;
    for (int h = 1; h <= n; h++) {
      for (int w = 1; w <= n; w++) {
        int t = h * w;
        if (n < t) break;
        a = Math.Min(a, Math.Abs(h - w) + (n - t));
      }
    }
    Console.WriteLine(a);
  }
}
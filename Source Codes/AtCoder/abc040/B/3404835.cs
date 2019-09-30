using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int a = int.MaxValue;
    for (int h = 1; h * h <= n; h++) {
      int w = n / h;
      a = Math.Min(a, Math.Abs(h - w) + n - h * w);
    }
    Console.WriteLine(a);
  }
}
using System;

class Program {
  static void Main() {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    Console.WriteLine(Math.Min(b - a, 10 - b + a));
  }
}
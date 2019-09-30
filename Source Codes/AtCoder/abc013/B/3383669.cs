using System;

class Program {
  static void Main() {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int d = Math.Abs(a - b);
    Console.WriteLine(Math.Min(d, 10 - d));
  }
}
using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int a = 100;
    while (n-- > 0) {
      a = Math.Min(a, int.Parse(Console.ReadLine()));
    }
    Console.WriteLine(a);
  }
}
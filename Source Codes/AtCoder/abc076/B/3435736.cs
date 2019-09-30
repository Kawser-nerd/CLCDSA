using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int k = int.Parse(Console.ReadLine());
    int a = 1;
    while (n-- > 0) {
      a = Math.Min(a * 2, a + k);
    }
    Console.WriteLine(a);
  }
}
using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int a = 64;
    while (a > 0) {
      if (a <= n) {
        Console.WriteLine(a);
        break;
      } else {
        a /= 2;
      }
    }
  }
}
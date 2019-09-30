using System;

class Program {
  static void Main() {
    var n = long.Parse(Console.ReadLine());
    long a = 1;
    for (long i = 1; i <= n; i++) {
      a = a * i % 1000000007;
    }
    Console.WriteLine(a);
  }
}
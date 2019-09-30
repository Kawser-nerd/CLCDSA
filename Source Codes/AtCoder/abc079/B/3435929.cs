using System;

class Program {
  static void Main() {
    var L = new long[87];
    L[0] = 2;
    L[1] = 1;
    var n = long.Parse(Console.ReadLine());
    for (int i = 2; i <= n; i++) {
      L[i] = L[i - 1] + L[i - 2];
    }
    Console.WriteLine(L[n]);
  }
}
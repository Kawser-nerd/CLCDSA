using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    Console.WriteLine(n - Input(n).Distinct().Count());
  }

  static IEnumerable<int> Input(int n) {
    for (int i = 0; i < n; i++) {
      yield return int.Parse(Console.ReadLine());
    }
  }
}
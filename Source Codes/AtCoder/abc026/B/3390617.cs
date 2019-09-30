using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = Input(n).OrderByDescending(x => x).ToArray();
    var r = 0;
    for (int i = 0; i < n; i++) {
      if ((i & 1) == 0)  r += a[i] * a[i];
      else r -= a[i] * a[i];
    }
    Console.WriteLine(r * Math.PI);
  }

  static IEnumerable<int> Input(int n) {
    for (int i = 0; i < n; i++) {
      yield return int.Parse(Console.ReadLine());
    }
  }
}
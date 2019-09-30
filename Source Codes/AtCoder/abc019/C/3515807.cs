using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var s = new HashSet<int>();
    for (int i = 0; i < n; i++) {
      while (true) {
        if (a[i] % 2 != 0) {
          s.Add(a[i]);
          break;
        }
        a[i] /= 2;
      }
    }
    Console.WriteLine(s.Count);
  }
}
using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = a[0];
    int m = a[1];
    int[,] v = new int[n, n];
    for (int i = 0; i < m; i++) {
      a = Console.ReadLine().Split().Select(int.Parse).ToArray();
      v[a[0] - 1, a[1] - 1] = 1;
      v[a[1] - 1, a[0] - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
      var s = new HashSet<int>();
      var t = new HashSet<int>();
      for (int j = 0; j < n; j++) {
        if (v[i, j] != 0) s.Add(j);
      }
      foreach (var e in s) {
        for (int k = 0; k < n; k++) {
          if (v[e, k] != 0) t.Add(k);
        }
      }
      s.Add(i);
      t.ExceptWith(s);
      Console.WriteLine(t.Count);
    }
  }
}
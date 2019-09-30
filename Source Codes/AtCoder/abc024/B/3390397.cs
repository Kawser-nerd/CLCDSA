using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int t = arr[1];
    int s = 0;
    var a = Input(n).ToArray();
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + t > a[i + 1]) {
        s += a[i + 1] - a[i];
      } else {
        s += t;
      }
    }
    Console.WriteLine(s + t);
  }

  static IEnumerable<int> Input(int n) {
    for (int i = 0; i < n; i++) {
      yield return int.Parse(Console.ReadLine());
    }
  }
}
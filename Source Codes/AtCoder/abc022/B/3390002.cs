using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    int cnt = 0, t = 0;
    foreach (var a in Input(int.Parse(Console.ReadLine())).OrderBy(x => x)) {
      if (t == a) cnt++;
      else t = a;
    }
    Console.WriteLine(cnt);
  }

  static IEnumerable<int> Input(int n) {
    for (int i = 0; i < n; i++) {
      yield return int.Parse(Console.ReadLine());
    }
  }
}
using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    int x = int.Parse(Console.ReadLine());
    List<int> lst = new List<int> {1};
    for (int b = 2; b * b <= x; b++) {
      for (int p = 2; ; p++) {
        int t = (int)Math.Pow(b, p);
        if (t <= x) lst.Add(t);
        else break;
      }
    }
    Console.WriteLine(lst.OrderByDescending(e => e).First());
  }
}
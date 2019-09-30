using System;
using System.Linq;

class Program {
  static void Main() {
    Console.ReadLine();
    var s = Console.ReadLine();
    int a = 0;
    for (int i = 1; i < s.Length; i++) {
      a = Math.Max(a, s.Substring(0, i).Intersect(s.Substring(i)).Count());
    }
    Console.WriteLine(a);
  }
}
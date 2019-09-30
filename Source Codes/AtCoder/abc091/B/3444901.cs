using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var s = Enumerable.Repeat(0, n).Select(x => Console.ReadLine()).ToArray();
    int m = int.Parse(Console.ReadLine());
    var t = Enumerable.Repeat(0, m).Select(x => Console.ReadLine()).ToArray();
    int ans = 0;
    foreach (var str in s) {
      ans = Math.Max(ans, s.Count(x => x == str) - t.Count(x => x == str));
    }
    Console.WriteLine(ans);
  }
}
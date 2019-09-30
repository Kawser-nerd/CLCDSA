using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int k = int.Parse(Console.ReadLine());
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int ans = 0;
    foreach (var x in arr) {
      ans += Math.Min(x, k - x) * 2;
    }
    Console.WriteLine(ans);
  }
}
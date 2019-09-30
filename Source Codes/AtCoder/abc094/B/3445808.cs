using System;
using System.Linq;

class Program {
  static void Main() {
    var arr= Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int m = arr[1];
    int x = arr[2];
    var a = Console.ReadLine().Split().Select(int.Parse);
    var L = Enumerable.Range(0, x);
    var r = Enumerable.Range(x, n - x + 1);
    Console.WriteLine(Math.Min(a.Intersect(L).Count(), a.Intersect(r).Count()));
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    var g = new[] { 0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1 };
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(g[a[0]] == g[a[1]] ? "Yes" : "No");
  }
}
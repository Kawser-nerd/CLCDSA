using System;
using System.Linq;

class Program {
  static void Main() {
    var arr= Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int x = arr[1];
    var m = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine()).Select(int.Parse).OrderBy(e => e).ToArray();
    Console.WriteLine(n + (x - m.Sum()) / m[0]);
  }
}
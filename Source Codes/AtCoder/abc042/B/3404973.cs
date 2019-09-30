using System;
using System.Linq;

class Program {
  static void Main() {
    var n = Console.ReadLine().Split().Select(int.Parse).ToArray()[0];
    var s = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine()).OrderBy(x => x);
    foreach (var item in s) {
      Console.Write(item);
    }
    Console.WriteLine();
  }
}
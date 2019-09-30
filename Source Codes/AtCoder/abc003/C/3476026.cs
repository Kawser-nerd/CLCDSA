using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var n = arr[0];
    var k = arr[1];
    var r = Console.ReadLine().Split().Select(int.Parse).OrderByDescending(x => x).Take(k);
    double a = 0;
    foreach (var i in r.Reverse()) {
      a = (a + i) / 2.0;
    }
    Console.WriteLine(a);
  }
}
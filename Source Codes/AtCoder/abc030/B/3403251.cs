using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var n = arr[0] % 12;
    var m = arr[1];
    var a = n * 30.0 + m / 2.0;
    var b = m * 6.0;
    var d = Math.Abs(a - b);
    Console.WriteLine(Math.Min(d, 360 - d));
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(double.Parse).ToArray();
    var x1 = arr[0];
    var y1 = arr[1];
    var x2 = arr[2];
    var y2 = arr[3];
    var x3 = arr[4];
    var y3 = arr[5];
    var a = Math.Abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) / 2.0;
    Console.WriteLine(a);
  }
}
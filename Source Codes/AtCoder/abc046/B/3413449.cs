using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var n = arr[0];
    var k = arr[1];
    Console.WriteLine(k * Math.Pow(k - 1, n - 1));
  }
}
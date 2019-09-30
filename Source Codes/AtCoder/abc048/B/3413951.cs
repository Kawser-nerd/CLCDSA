using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(ulong.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var x = arr[2];
    var ans = b / x - a / x;
    Console.WriteLine(a % x == 0 ? ans + 1 : ans);
  }
}
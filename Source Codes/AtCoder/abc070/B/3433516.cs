using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = arr[3];
    var L = Math.Max(a, c);
    var r = Math.Min(b, d);
    Console.WriteLine(L <= r ? r - L : 0);
  }
}
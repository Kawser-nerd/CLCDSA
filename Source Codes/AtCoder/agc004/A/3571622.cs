using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(long.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var c = arr[2];
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
      Console.WriteLine(0);
    } else {
      Console.WriteLine(Math.Min(a * b, Math.Min(a * c, b * c)));
    }
  }
}
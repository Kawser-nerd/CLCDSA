using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var ans = Math.Max((a + 1) * b, a * (b + 1));
    Console.WriteLine(ans);
  }
}
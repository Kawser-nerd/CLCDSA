using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(long.Parse).ToArray();
    var n = arr[0];
    var h = arr[1];
    arr = Console.ReadLine().Split().Select(long.Parse).ToArray();
    var a = arr[0];
    var b = arr[1];
    var c = arr[2];
    var d = arr[3];
    var e = arr[4];
    long ans = long.MaxValue;
    for (long i = 0; i <= n; i++) {
      var j = Math.Max(0, (long)Math.Floor((double)((n - i) * e - h - b * i) / (d + e) + 1));
      ans = Math.Min(ans, i * a + j * c);
    }
    Console.WriteLine(ans);
  }
}
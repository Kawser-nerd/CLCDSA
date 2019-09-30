using System;
using System.Linq;

class Program {
  static void Main() {
    const double EPS = 1e-7;
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int txa = arr[0];
    int tya = arr[1];
    int txb = arr[2];
    int tyb = arr[3];
    int t = arr[4];
    int v = arr[5];
    int n = int.Parse(Console.ReadLine());
    while (n-- > 0) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int x = arr[0];
      int y = arr[1];
      var a = Math.Sqrt(Math.Pow((txa - x), 2) + Math.Pow((tya - y), 2));
      var b = Math.Sqrt(Math.Pow((txb - x), 2) + Math.Pow((tyb - y), 2));
      if (a + b <= t * v + EPS) {
        Console.WriteLine("YES");
        return;
      }
    }
    Console.WriteLine("NO");
  }
}
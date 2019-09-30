using System;
using System.Linq;

class Program {
  static void Main() {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
      ans += a[0] * a[1] / 10;
    }
    Console.WriteLine(ans);
  }
}
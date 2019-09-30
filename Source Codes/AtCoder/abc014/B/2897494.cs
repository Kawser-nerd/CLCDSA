using System;
using System.Linq;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = a[0];
    int x = a[1];
    int ans = 0;
    a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    for (int i = 0; i < n; i++) {
      if ((x & (1 << i)) != 0) {
        ans += a[i];
      }
    }
    Console.WriteLine(ans);
  }
}
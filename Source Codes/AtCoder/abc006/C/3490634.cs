using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int m = arr[1];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 1; j++) {
        int k = n - i - j;
        if (k < 0) continue;
        if (i * 2 + j * 3 + k * 4 == m) {
          Console.WriteLine($"{i} {j} {k}");
          return;
        }
      }
    }
    Console.WriteLine("-1 -1 -1 ");
  }
}
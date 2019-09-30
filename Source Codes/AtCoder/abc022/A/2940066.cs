using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int s = arr[1];
    int t = arr[2];
    int w = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      w += int.Parse(Console.ReadLine());
      if (s <= w && w <= t) ans++;
    }
    Console.WriteLine(ans);
  }
}
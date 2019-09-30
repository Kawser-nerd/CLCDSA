using System;
using System.Linq;

class Program {
  static void Main() {
    int[] d = new int[1000010];
    int n = int.Parse(Console.ReadLine());
    for (int i = 0; i < n; i++) {
      var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int a = arr[0];
      int b = arr[1];
      d[a]++;
      d[b + 1]--;
    }
    int ans = d[0];
    for (int i = 1; i <= 1000000; i++) {
      d[i] += d[i - 1];
      ans = Math.Max(ans, d[i]);
    }
    Console.WriteLine(ans);
  }
}
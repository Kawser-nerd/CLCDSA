using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var n = arr[0];
    var k = arr[1];
    var t = new int[n][];
    for (int i = 0; i < n; i++) {
      t[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
    }
    Console.WriteLine(Dfs(0, 0, t, n, k) ? "Found" : "Nothing");
  }

  static bool Dfs(int d, int x, int[][] t, int n, int k) {
    if (d == n) return x == 0;
    for (int i = 0; i < k; i++) {
      if (Dfs(d + 1, x ^ t[d][i], t, n, k)) return true;
    }
    return false;
  }
}
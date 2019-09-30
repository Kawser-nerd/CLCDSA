using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    const int INF = 1000000000;
    const int MOD = 1000000007;
    int n = int.Parse(Console.ReadLine());
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0] - 1;
    int b = arr[1] - 1;
    int m = int.Parse(Console.ReadLine());
    var g = new bool[n, n];
    for (int i = 0; i < m; i++) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int x = arr[0] - 1;
      int y = arr[1] - 1;
      g[x, y] = true;
      g[y, x] = true;
    }
    var d = Enumerable.Repeat(0, n).Select(x => x = INF).ToArray();
    var cnt = new long[n];
    var que = new Queue<int>();
    que.Enqueue(a);
    d[a] = 0;
    cnt[a] = 1;
    while (que.Count > 0) {
      int u = que.Dequeue();
      if (u == b) break;
      for (int v = 0; v < n; v++) {
        if (g[u, v])  {
          if (d[v] == INF) {
            d[v] = d[u] + 1;
            cnt[v] += cnt[u] % MOD;
            que.Enqueue(v);
          } else if (d[u] + 1 == d[v]) {
            cnt[v] += cnt[u] % MOD;
          }
        }
      }
    }
    Console.WriteLine(cnt[b] % MOD);
  }
}
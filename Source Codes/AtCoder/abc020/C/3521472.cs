using System;
using System.Linq;
using System.Collections.Generic;

struct P {
  public int x, y;
  public P(int X, int Y) { x = X; y = Y; }
}

class Program {
  static readonly long INF = long.MaxValue;
  static readonly int[] dx = { 1, 0, -1, 0 };
  static readonly int[] dy = { 0, 1, 0, -1 };
  static int h, w, t, sx, sy, gx, gy;

  static bool Bfs(int x, string[] s) {
    var que = new Queue<P>();
    long[,] d = new long[h, w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        d[i, j] = INF;
      }
    }
    que.Enqueue(new P(sx, sy));
    d[sy, sx] = 0;
    while (que.Count > 0) {
      P p = que.Dequeue();
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (0 <= nx && nx < w && 0 <= ny && ny < h) {
          var nd = d[p.y, p.x] + (s[ny][nx] == '#' ? x : 1);
          if (nd < d[ny, nx]) {
            d[ny, nx] = nd;
            que.Enqueue(new P(nx, ny));
          }
        }
      }
    }
    return d[gy, gx] <= t;
  }

  static int BinarySearch(int L, int r, string[] s) {
    while (r - L > 1) {
      var mid = (L + r) / 2;
      if (Bfs(mid, s)) L = mid;
      else r = mid;
    }
    return L;
  }

  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    h = a[0];
    w = a[1];
    t = a[2];
    var s = new string[h];
    for (int i = 0; i < h; i++) {
      s[i] = Console.ReadLine();
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if(s[i][j] == 'S') { sx = j; sy = i; }
        else if(s[i][j] == 'G') { gx = j; gy = i; }
      }
    }
    Console.WriteLine(BinarySearch(1, 1000000000, s));
  }
}
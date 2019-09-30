using System;
using System.Linq;

struct point {
  public int x, y;
  public int Dist(int ax, int ay) {
    return Math.Abs(x - ax) + Math.Abs(y - ay);
  }
}

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int m = arr[1];
    var a = new point[n];
    var c = new point[m];
    for (int i = 0; i < n; i++) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      a[i].x = arr[0];
      a[i].y = arr[1];
    }
    for (int i = 0; i < m; i++) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      c[i].x = arr[0];
      c[i].y = arr[1];
    }
    for (int i = 0; i < n; i++) {
      int ans = 0;
      int min = int.MaxValue;
      for (int j = 0; j < m; j++) {
        int t = c[j].Dist(a[i].x, a[i].y);
        if (t < min) {
          min = t;
          ans = j + 1;
        }
      }
      Console.WriteLine(ans);
    }
  }
}
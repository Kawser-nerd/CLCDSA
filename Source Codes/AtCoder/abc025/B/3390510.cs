using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int a = arr[1];
    int b = arr[2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      var sd = Console.ReadLine().Split().ToArray();
      string s = sd[0];
      int d = int.Parse(sd[1]);
      int t = 0;
      if (d < a) t = a;
      else if (a <= d && d <= b) t = d;
      else t = b;
      if (s == "East") ans += t;
      else ans -= t;
    }
    if (ans < 0) {
      Console.WriteLine($"West {-ans}");
    } else if (ans > 0) {
      Console.WriteLine($"East {ans}");
    } else {
      Console.WriteLine(0);
    }
  }
}
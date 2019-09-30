using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int ans = 0;
    for (int i = 105; i <= n; i += 2) {
      int cnt = 0;
      for (int j = 1; j <= i; j += 2) {
        if (i % j == 0) cnt++;
      }
      if (cnt == 8) ans++;
    }
    Console.WriteLine(ans);
  }
}
using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int m = 0, a = 1;
    for (int i = 1; i <= n; i++) {
      int t = Cnt(i);
      if (m < t) {
        m = t;
        a = i;
      }
    }
    Console.WriteLine(a);
  }

  static int Cnt(int n) {
    int cnt = 0;
    while (n % 2 == 0) {
      cnt++;
      n /= 2;
    }
    return cnt;
  }
}
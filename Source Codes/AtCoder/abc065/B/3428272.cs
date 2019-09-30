using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = new int[n + 1];
    var p = new int[n + 1];
    int b = 1, cnt = 0;
    var f = true;
    for (int i = 1; i <= n; i++) {
      a[i] = int.Parse(Console.ReadLine());
    }
    while (b != 2) {
      p[b]++;
      if (p[a[b]] > 1) {
        f = false;
        break;
      }
      b = a[b];
      cnt++;
    }
    Console.WriteLine(f ? cnt : -1);
  }
}
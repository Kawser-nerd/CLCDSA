using System;

class Program {
  static void Main() {
    int MOD = 10007;
    int[] a = new int[1000001];
    a[3] = 1;
    int n = int.Parse(Console.ReadLine());
    for (int i = 4; i <= n; i++) {
      a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % MOD;
    }
    Console.WriteLine(a[n]);
  }
}
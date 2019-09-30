using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int[] m = new int[100001];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int t = int.Parse(Console.ReadLine());
      m[t]++;
      if (m[t] > 1) cnt++;
    }
    Console.WriteLine(cnt);
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.ReadLine();
    var p = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int[] m = new int[n];
    m[a[0] - 1] = m[a[1] - 1] = 1;
    foreach (var t in p) {
      m[t - 1]++;
    }
    bool f = true;
    foreach (var t in m) {
      if (t > 1) {
        f = false;
        break;
      }
    }
    Console.WriteLine(f ? "YES" : "NO");
  }
}
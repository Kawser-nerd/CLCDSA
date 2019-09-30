using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = Console.ReadLine().Split().Select(int.Parse);
    var sum = a.Sum();
    if (sum % n != 0) {
      Console.WriteLine(-1);
      return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a.Take(i + 1).Sum() != sum / n * (i + 1)) ans++;
    }
    Console.WriteLine(ans);
  }
}
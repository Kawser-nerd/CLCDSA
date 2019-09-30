using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != 0) {
        sum += a[i];
        cnt++;
      }
    }
    int ans = (int)Math.Ceiling((double)sum / cnt);
    Console.WriteLine(ans);
  }
}
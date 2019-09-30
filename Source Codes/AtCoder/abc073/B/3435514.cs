using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int ans = 0;
    while (n-- > 0) {
      var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int L = arr[0];
      int r = arr[1];
      ans += r - L + 1;
    }
    Console.WriteLine(ans);
  }
}
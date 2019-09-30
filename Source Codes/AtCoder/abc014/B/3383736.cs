using System;
using System.Linq;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = a[0];
    int x = a[1];
    a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if ((x >> i & 1) == 1) sum += a[i];
    }
    Console.WriteLine(sum);
  }
}
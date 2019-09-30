using System;
using System.Linq;

class Program {
  static int Hoge(int a, int d) {
    int res = 0;
    for (int i = 0; 1 + i * a <= d; i++) res++;
    return res;
  }

  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int d = arr[0];
    int x = arr[1];
    var a = Enumerable.Repeat(0, n)
            .Select(_ => Console.ReadLine()).Select(int.Parse).Select(e => Hoge(e, d)).Sum();
    Console.WriteLine(a + x);
  }
}
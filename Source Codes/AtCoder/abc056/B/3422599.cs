using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int w = arr[0];
    int a = arr[1];
    int b = arr[2];
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    if (a + w >= b) Console.WriteLine(0);
    else Console.WriteLine(b - a - w);
  }
}
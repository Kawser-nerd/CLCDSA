using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int d = arr[0];
    int n = arr[1];
    if (n < 100) {
      Console.WriteLine(Math.Pow(100, d) * n);
    } else {
      Console.WriteLine(Math.Pow(100, d) * 101);
    }
  }
}
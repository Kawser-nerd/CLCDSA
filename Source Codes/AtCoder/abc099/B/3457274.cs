using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    Console.WriteLine((b - a) * (b - a + 1) / 2 - b);
  }
}
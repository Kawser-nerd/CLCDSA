using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int a = arr[1];
    int b = arr[2];
    Console.WriteLine(Math.Min(n * a, b));
  }
}
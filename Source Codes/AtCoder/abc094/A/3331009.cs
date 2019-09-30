using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int x = arr[2];
    Console.WriteLine(a <= x && x <= a + b ? "YES" : "NO");
  }
}
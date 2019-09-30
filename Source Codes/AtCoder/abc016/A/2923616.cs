using System;
using System.Linq;

class Program {
  static void Main() {
    int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(a[0] % a[1] == 0 ? "YES" : "NO");
  }
}
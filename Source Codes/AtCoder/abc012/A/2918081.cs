using System;
using System.Linq;

class Program {
  static void Main() {
    int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine("{0} {1}", a[1], a[0]);
  }
}
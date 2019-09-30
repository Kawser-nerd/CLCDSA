using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int x = arr[1];
    Console.WriteLine(Math.Min(x - 1, n - x));
  }
}
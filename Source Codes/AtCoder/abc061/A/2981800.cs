using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    Console.WriteLine(a <= c && c <= b ? "Yes" : "No");
  }
}
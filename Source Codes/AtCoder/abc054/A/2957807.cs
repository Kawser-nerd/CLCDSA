using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    if (a == 1) a = 14;
    if (b == 1) b = 14;
    if (a > b) Console.WriteLine("Alice");
    else if (a < b) Console.WriteLine("Bob");
    else Console.WriteLine("Draw");
  }
}
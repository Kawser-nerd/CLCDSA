using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x = arr[0];
    int y = arr[1];
    Console.WriteLine(x < y ? "Better" : "Worse");
  }
}
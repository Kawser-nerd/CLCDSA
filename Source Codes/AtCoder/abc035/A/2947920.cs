using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int w = arr[0];
    int h = arr[1];
    Console.WriteLine(w * 3 == h * 4 ? "4:3" : "16:9");
  }
}
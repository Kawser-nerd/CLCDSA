using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x = arr[0];
    int y = arr[1];
    int z = arr[2];
    Console.WriteLine((x - z) / (y + z));
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x = arr[0];
    int a = arr[1];
    int b = arr[2];
    if (Math.Abs(x - a) < Math.Abs(x - b)) {
      Console.WriteLine("A");
    } else {
      Console.WriteLine("B");
    }
  }
}
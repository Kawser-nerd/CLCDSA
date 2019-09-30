using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
      Console.WriteLine("Possible");
    } else {
      Console.WriteLine("Impossible");
    }
  }
}
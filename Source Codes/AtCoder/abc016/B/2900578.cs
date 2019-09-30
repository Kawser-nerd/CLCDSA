using System;
using System.Linq;

class Program {
  static void Main() {
    var n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = n[0];
    int b = n[1];
    int c = n[2];
    if (a + b == c && a - b != c) {
      Console.WriteLine("+");
    } else if (a + b != c && a - b == c) {
      Console.WriteLine("-");
    } else if (a + b == c && a - b == c) {
      Console.WriteLine("?");
    } else {
      Console.WriteLine("!");
    }
  }
}
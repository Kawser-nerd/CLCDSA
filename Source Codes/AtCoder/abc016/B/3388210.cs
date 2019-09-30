using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    var s = "!";
    if (a + b == c && a - b != c) s = "+";
    else if (a + b != c && a - b == c) s = "-";
    else if (a + b == c && a - b == c) s = "?";
    Console.WriteLine(s);
  }
}
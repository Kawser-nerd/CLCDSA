using System;
using System.Linq;

class Program {
  static void Main() {
    Console.ReadLine();
    var a = Console.ReadLine().Split().Distinct().Count();
    Console.WriteLine(a == 3 ? "Three" : "Four");
  }
}
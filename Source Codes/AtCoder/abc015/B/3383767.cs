using System;
using System.Linq;

class Program {
  static void Main() {
    Console.ReadLine();
    var a = Console.ReadLine().Split().Select(int.Parse).Where(x => x != 0).Average();
    Console.WriteLine(Math.Ceiling(a));
  }
}
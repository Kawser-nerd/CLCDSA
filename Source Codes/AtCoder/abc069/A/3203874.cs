using System;
using System.Linq;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).Select(x => x - 1).Aggregate((n, m) => n * m);
    Console.WriteLine(a);
  }
}
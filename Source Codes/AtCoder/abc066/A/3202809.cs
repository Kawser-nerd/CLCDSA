using System;
using System.Linq;

class Program {
  static void Main() {
    var a = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).Take(2).Sum();
    Console.WriteLine(a);
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    var f = Console.ReadLine().GroupBy(x => x).All(x => x.Count() == 1);
    Console.WriteLine(f ? "yes" : "no");
  }
}
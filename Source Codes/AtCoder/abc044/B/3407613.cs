using System;
using System.Linq;

class Program {
  static void Main() {
    var w = Console.ReadLine();
    Console.WriteLine(w.GroupBy(x => x).All(x => x.Count() % 2 == 0) ? "Yes" : "No");
  }
}
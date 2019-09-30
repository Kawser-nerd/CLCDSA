using System;
using System.Linq;

class Program {
  static void Main() {
    var s = new string(Console.ReadLine().OrderBy(x => x).ToArray());
    Console.WriteLine(s == "abc" ? "Yes" : "No");
  }
}
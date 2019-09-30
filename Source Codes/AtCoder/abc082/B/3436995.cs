using System;
using System.Linq;

class Program {
  static void Main() {
    var s = new string(Console.ReadLine().OrderBy(x=>x).ToArray());
    var t = new string(Console.ReadLine().OrderByDescending(x => x).ToArray());
    Console.WriteLine(s.CompareTo(t) == -1 ? "Yes" : "No");
  }
}
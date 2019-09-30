using System;
using System.Linq;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    if (s.Contains('N') == s.Contains('S') && s.Contains('E') == s.Contains('W')) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }
  }
}
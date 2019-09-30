using System;

class Program {
  static void Main() {
    var w = Console.ReadLine();
    var s = "aiueo";
    foreach (var c in w) {
      if (s.Contains(c.ToString())) continue;
      Console.Write(c);
    }
    Console.WriteLine();
  }
}
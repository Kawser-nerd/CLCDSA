using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var t = Console.ReadLine();
    s = s + s;
    Console.WriteLine(s.Contains(t) ? "Yes" : "No");
  }
}
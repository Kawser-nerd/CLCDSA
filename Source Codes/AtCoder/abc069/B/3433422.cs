using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    Console.WriteLine($"{s.Substring(0, 1)}{s.Length - 2}{s.Substring(s.Length - 1, 1)}");
  }
}
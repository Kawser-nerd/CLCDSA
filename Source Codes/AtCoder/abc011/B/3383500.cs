using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    Console.WriteLine(s.Substring(0, 1).ToUpper() + s.Substring(1).ToLower());
  }
}
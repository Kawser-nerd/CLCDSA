using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    while (true) {
      s = s.Substring(0, s.Length - 1);
      if ((s.Length & 1) == 1) continue;
      var a = s.Substring(0, s.Length / 2);
      var b = s.Substring(s.Length / 2);
      if (a == b) {
        Console.WriteLine(s.Length);
        break;
      }
    }
  }
}
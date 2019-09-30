using System;

class Program {
  static void Main() {
    var a = Console.ReadLine();
    var b = Console.ReadLine();
    string[] s = { "GREATER", "LESS", "EQUAL" };
    var n = 2;
    if (a.Length > b.Length) n = 0;
    else if (a.Length < b.Length) n = 1;
    else {
      int t = a.CompareTo(b);
      if (t == 1) n = 0;
      else if (t == -1) n = 1;
    }
    Console.WriteLine(s[n]);
  }
}
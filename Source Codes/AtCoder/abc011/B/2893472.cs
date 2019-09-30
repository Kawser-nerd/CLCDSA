using System;

class Program {
  static void Main() {
    string s = Console.ReadLine();
    s = char.ToUpper(s[0]) + s.ToLower().Substring(1);
    Console.WriteLine(s);
  }
}
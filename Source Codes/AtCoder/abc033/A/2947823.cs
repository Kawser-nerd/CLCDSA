using System;

class Program {
  static void Main() {
    string s = Console.ReadLine();
    if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
      Console.WriteLine("SAME");
    } else {
      Console.WriteLine("DIFFERENT");
    }
  }
}
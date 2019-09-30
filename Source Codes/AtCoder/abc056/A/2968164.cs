using System;

class Program {
  static void Main() {
    string s = Console.ReadLine();
    if (s == "H H" || s == "D D") Console.WriteLine("H");
    else Console.WriteLine("D");
  }
}
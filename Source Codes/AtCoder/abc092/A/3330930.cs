using System;
using static System.Console;

class Program {
  static void Main() {
    int a = int.Parse(ReadLine());
    int b = int.Parse(ReadLine()); ;
    int c = int.Parse(ReadLine()); ;
    int d = int.Parse(ReadLine()); ;
    WriteLine(Math.Min(a, b) + Math.Min(c, d));
  }
}
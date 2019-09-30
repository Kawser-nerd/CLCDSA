using System;
class Program {
  static void Main(string[] args) {
    int x = int.Parse(Console.ReadLine());
    if (x < 1200) {
      Console.Write("ABC");
    } else {
      Console.Write("ARC");
    }
  }
}
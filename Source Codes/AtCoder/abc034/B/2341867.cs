using System;
class Program {
  static void Main(string[] arg) {
    var a = long.Parse(Console.ReadLine());
    Console.WriteLine(a % 2 == 0 ? a - 1 : a + 1);
  }
}
using System;

class Program {
  static void Main() {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    Console.WriteLine(a % b == 0 ? 0 : b - (a % b));
  }
}
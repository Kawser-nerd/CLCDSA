using System;

class Program {
  static void Main() {
    int x = int.Parse(Console.ReadLine());
    int a = x / 10;
    int b = x % 10;
    Console.WriteLine(a + b);
  }
}
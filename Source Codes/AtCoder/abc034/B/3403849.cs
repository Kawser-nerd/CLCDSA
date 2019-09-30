using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    Console.WriteLine(n % 2 == 1 ? n + 1 : n - 1);
  }
}
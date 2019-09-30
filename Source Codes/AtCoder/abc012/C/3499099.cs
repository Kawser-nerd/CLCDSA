using System;

class Program {
  static void Main() {
    int n = 2025 - int.Parse(Console.ReadLine());
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        if (i * j == n) Console.WriteLine($"{i} x {j}");
      }
    }
  }
}
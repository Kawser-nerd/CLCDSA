using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    for (int i = 0; i <= 25; i++) {
      for (int j = 0; j <= 14; j++) {
        if (i * 4 + j * 7 == n) {
          Console.WriteLine("Yes");
          return;
        }
      }
    }
    Console.WriteLine("No");
  }
}
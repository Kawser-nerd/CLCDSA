using System;

class Program {
  static void Main() {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int n = int.Parse(Console.ReadLine());
    for (; ; n++) {
      if (n % a == 0 && n % b == 0) {
        Console.WriteLine(n);
        break;
      }
    }
  }
}
using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int c = int.Parse(Console.ReadLine());
    if (n == a || n == b || n == c) {
      Console.WriteLine("NO");
      return;
    }
    for (int i = 0; i < 100; i++) {
      if (n - 3 != a && n - 3 != b && n - 3 != c)  n -= 3;
      else if (n - 2 != a && n - 2 != b && n - 2 != c) n -= 2;
      else if (n - 1 != a && n - 1 != b && n - 1 != c)  n--;
      if (n <= 0) {
        Console.WriteLine("YES");
        return;
      }
    }
    Console.WriteLine("NO");
  }
}
using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var s = Console.ReadLine();
    int x = 0, a = 0;
    foreach (var c in s) {
      if (c == 'I') x++;
      else x--;
      a = Math.Max(a, x);
    }
    Console.WriteLine(a);
  }
}
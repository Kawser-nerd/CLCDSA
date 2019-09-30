using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var s = Console.ReadLine();
    var t = Console.ReadLine();
    int i = 0;
    for ( ; i < n; i++) {
      if (s.Substring(i) == t.Substring(0, n - i)) break;
    }
    Console.WriteLine(i + t.Length);
  }
}
using System;

class Program {
  static void Main() {
    var o = Console.ReadLine();
    var e = Console.ReadLine();
    int i = 0;
    for ( ; i < e.Length; i++) {
      Console.Write($"{o[i]}{e[i]}");
    }
    Console.WriteLine(i < o.Length ? $"{o[i]}" : "");
  }
}
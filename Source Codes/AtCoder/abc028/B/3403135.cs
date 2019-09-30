using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    var a = new int[6];
    foreach (var c in s) a[c - 65]++;
    Console.WriteLine(string.Join(" ", a));
  }
}
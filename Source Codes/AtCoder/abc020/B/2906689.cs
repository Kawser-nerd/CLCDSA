using System;

class Program {
  static void Main() {
    var s = Console.ReadLine().Split();
    Console.WriteLine(int.Parse(s[0] + s[1]) * 2);
  }
}
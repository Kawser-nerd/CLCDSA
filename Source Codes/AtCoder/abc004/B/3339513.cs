using System;
using System.Linq;

class Program {
  static void Main() {
    var s = new string[4];
    for (int i = 0; i < 4; i++) {
      s[i] = new string(Console.ReadLine().Reverse().ToArray());
    }
    Array.Reverse(s);
    foreach (var i in s) {
      Console.WriteLine(i);
    }
  }
}
using System;
using System.Linq;

class Program {
  static void Main() {
    var s = new string(Console.ReadLine().Distinct().ToArray());
    if (s.Any(x => x == 'N') == s.Any(x => x == 'S') && s.Any(x => x == 'E') == s.Any(x => x == 'W')) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }
  }
}
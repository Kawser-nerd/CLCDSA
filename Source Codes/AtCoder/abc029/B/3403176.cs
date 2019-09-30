using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    Console.WriteLine(Input().Where(x => x.Contains("r")).Count());
  }

  static IEnumerable<string> Input() {
    for (int i = 0; i < 12; i++) {
      yield return Console.ReadLine();
    }
  }
}
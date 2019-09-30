using System;
using System.Collections.Generic;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int k = int.Parse(Console.ReadLine());
    var set = new HashSet<string>();
    for (int i = 0; i + k <= s.Length; i++) {
      set.Add(s.Substring(i, k));
    }
    Console.WriteLine(set.Count);
  }
}
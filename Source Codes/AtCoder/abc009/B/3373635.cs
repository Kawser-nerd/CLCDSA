using System;
using System.Collections.Generic;

class Program {
  static void Main() {
    var set = new SortedSet<int>();
    int n = int.Parse(Console.ReadLine());
    while (n-- > 0) {
      set.Add(int.Parse(Console.ReadLine()));
    }
    set.Remove(set.Max);
    Console.WriteLine(set.Max);
  }
}
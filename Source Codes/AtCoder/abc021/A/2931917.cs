using System;
using System.Collections.Generic;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    List<int> a = new List<int>();
    for (int i = 0; i < 4; i++) {
      if ((n & 1 << i) != 0) a.Add(1 << i);
    }
    Console.WriteLine(a.Count);
    a.ForEach(Console.WriteLine);
  }
}
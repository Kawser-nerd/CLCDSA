using System;
using System.Linq;
using System.Collections.Generic;

class Program {
  static void Main() {
    string s = Console.ReadLine();
    int n = int.Parse(Console.ReadLine());
    var list = new List<string>();
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        list.Add(s[i].ToString() + s[j].ToString());
      }
    }
    Console.WriteLine(list.OrderBy(x => x).ElementAt(n - 1));
  }
}
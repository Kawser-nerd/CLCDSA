using System;
using System.Collections.Generic;

class Program {
  static void Main(string[] args) {
    string n = Console.ReadLine();
    int N = int.Parse(n);

    var map = new Dictionary<int, bool>();
    
    for (int i=0; i<N; i++) {
      string s = Console.ReadLine();
      int v = int.Parse(s);
      bool b;
      if (map.TryGetValue(v, out b)) {
        map.Remove(v);
      } else {
        map.Add(v, true);
      }
    }

    Console.WriteLine(map.Count);
  }
}
using System;
using System.Collections.Generic;

class Program
{
  static void Main(string[] args)
  {
    string str = Console.ReadLine();
    int n = int.Parse(str);

    Dictionary<int, bool> map = new Dictionary<int, bool>();
    for (int i=0; i<n; i++) {
      string t_str = Console.ReadLine();
      int t = int.Parse(t_str);
      if (map.ContainsKey(t)) {
        map.Remove(t);
      } else {
        map.Add(t, true);
      }
    }

    Console.WriteLine(map.Count);
    return;
  }
}
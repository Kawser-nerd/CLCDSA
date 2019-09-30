using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
  static void Main(string[] args)
  {
    Console.ReadLine();
    List<int> l = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
    l.Sort(delegate (int mca1, int mca2) { return (int)(mca2 - mca1); });
    int u = 0;
    for (int i = 0; i < l.Count; i += 2) { u += l[i]; }
    Console.WriteLine(u.ToString());
  }
}
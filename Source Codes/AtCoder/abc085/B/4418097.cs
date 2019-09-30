using System;
using System.Collections.Generic;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    HashSet<int> d = new HashSet<int>();
    for (int i = 0; i < n; i ++) d.Add(int.Parse(Console.ReadLine()));
    Console.WriteLine(d.Count);
  }
}
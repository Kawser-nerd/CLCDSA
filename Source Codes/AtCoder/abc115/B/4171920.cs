using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  int N = int.Parse(Console.ReadLine());
  List<int> l = new List<int>();
  for (int i = 0; i < N; i++) { l.Add(int.Parse(Console.ReadLine())); }
  l.Sort();
  int s = l.Sum() - l[l.Count - 1] / 2;
  Console.WriteLine(s.ToString());
 }
}
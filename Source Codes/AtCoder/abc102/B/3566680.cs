using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  Console.ReadLine();
  List<int> A = new List<int>();
  string[] S = Console.ReadLine().Split(' ');
  for (int i = 0; i < S.Length; i++) { A.Add(int.Parse(S[i])); }
  Console.WriteLine((A.Max() - A.Min()).ToString());
 }
}
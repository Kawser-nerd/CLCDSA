using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  string N = Console.ReadLine();
  List<string> S = Console.ReadLine().Trim().Split(' ').ToList();
  string u = "Three";
  if (S.Contains("Y")) { u = "Four"; }
  Console.WriteLine("{0}", u);
 }
}
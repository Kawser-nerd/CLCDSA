using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  List<char> S = Console.ReadLine().ToList();
  S.Sort();
  string u = "No";
  if (new string(S.ToArray()) == "abc") { u = "Yes"; }
  Console.WriteLine("{0}", u);
 }
}
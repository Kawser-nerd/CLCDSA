using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  char[] cS = Console.ReadLine().Trim().ToArray();
  List<int> lS = new List<int>() { 0, 0, 0, 0, 0, 0, };
  for (int i = 0; i < cS.Length; i++) { lS[(int)cS[i] - 65] += 1; }
  string sO = "";
  for (int i = 0; i < lS.Count; i++) { sO +=lS[i].ToString() + " "; }
  Console.WriteLine("{0}", sO.Trim().ToString());
 }
}
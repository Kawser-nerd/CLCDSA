using System;
using System.Collections.Generic;
using System.Text;
class Program
{
 static void Main(string[] args)
 {
  string[] sInp = Console.ReadLine().Trim().Split(' ');
  int iN = int.Parse(sInp[0]);
  int iL = int.Parse(sInp[1]);
  List<string> lstInp = new List<string>();
  for (int i = 0; i < iN; i++) { lstInp.Add(Console.ReadLine().Trim()); }
  lstInp.Sort();
  StringBuilder sOut = new StringBuilder();
  for (int i = 0; i < iN; i++) { sOut.Append(lstInp[i]); }
  Console.WriteLine("{0}", sOut.ToString());
 }
}
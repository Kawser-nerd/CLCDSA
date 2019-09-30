using System;
class Program
{
 static void Main(string[] args)
 {
  int iN = int.Parse(Console.ReadLine().Trim().Replace(" ", ""));
  string sO = "NO"; 
  if (iN % 4 == 0) { sO = "YES"; }
  Console.WriteLine(sO);
 }
}
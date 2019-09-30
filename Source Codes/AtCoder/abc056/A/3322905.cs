using System;
class Program
{
 static void Main(string[] args)
 {
  string[] sS = Console.ReadLine().Trim().Split(' ');
  string sOut = "D";
  if (sS[0] == sS[1]) { sOut = "H"; }
  Console.WriteLine(sOut);
 }
}
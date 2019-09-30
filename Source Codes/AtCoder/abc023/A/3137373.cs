using System;
using System.Linq;
class Program
{
 static void Main(string[] args)
 {
  char[] S = Console.ReadLine().Trim().ToArray();
  Console.WriteLine("{0}", ((int)S[0] + (int)S[1] - 96).ToString());
 }
}
using System;
class Program
{
 static void Main(string[] args)
 {
  int D = int.Parse(Console.ReadLine());
  string s = "Christmas";
  for (int i = 24; i >= D; i--) { s += " Eve"; }
  Console.WriteLine(s);
 }
}
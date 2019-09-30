using System;
class Program
{
 static void Main(string[] args)
 {
  string[] s = Console.ReadLine().Split(' ');
  int D = int.Parse(s[0]), N = int.Parse(s[1]); N = N == 100 ? 101 : N;
  Console.WriteLine((N * Math.Pow(100, D)).ToString());
 }
}
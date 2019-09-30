using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    string[] s = Console.ReadLine().Split().ToArray();
    int n = int.Parse(s[0] + s[1]);
    Console.WriteLine(n * 2);
  }
}
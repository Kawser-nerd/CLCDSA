using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Array.Sort(n);
    Console.WriteLine(n[1]);
  }
}
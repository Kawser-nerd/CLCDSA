using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Array.Sort(s);
    Array.Reverse(s);
    Console.WriteLine(s.Where((value, index) => index % 2 == 0).Sum() - s.Where((value, index) => index % 2 == 1).Sum());
  }
}
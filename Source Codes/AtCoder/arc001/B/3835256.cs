using System;
using System.Linq;

class Program
{
  static void Main()
  {
    int n = int.Parse(Console.ReadLine());
    int[] ans = Console.ReadLine().ToCharArray()
      	.Select(x => int.Parse(x.ToString())).ToArray();
    int[] hist =
      Enumerable.Range(1, 4)
      	.Select(x => ans.Count(y => y == x)).ToArray();
    Console.WriteLine($"{hist.Max()} {hist.Min()}");
    //Console.WriteLine(string.Join(",", hist));
  }
}
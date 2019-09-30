using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] a = Console.ReadLine().Split(' ').Select(int.Parse).Where(value => value != 0).ToArray();
    double ans = (double)a.Sum()/a.Count();
    Console.WriteLine(Math.Ceiling(ans));
  }
}
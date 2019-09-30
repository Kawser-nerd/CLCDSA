using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    double[] s = Console.ReadLine().Split().Select(double.Parse).ToArray();
    Console.WriteLine(s[0]/s[1]);
  }
}
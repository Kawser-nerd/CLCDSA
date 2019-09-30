using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    if ((s[0] * s[1]) % 2 == 0) Console.WriteLine("Even");
    else Console.WriteLine("Odd");
  }
}
using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int sum = 0;
    for (int i = 0; i < 3; i ++) {
      int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
      sum += (x[0] * x[1]) /10;
    }
    Console.WriteLine(sum);
  }
}
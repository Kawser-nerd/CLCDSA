using System;
using System.Collections.Generic;
using System.Linq;

class Program
{     
    public Program()
    {
      int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int n = inputs[0];
      int m = inputs[1];
      int result = 
        Enumerable.Range(1, (int)Math.Sqrt(m) + 1)
        .Where(x => m % x == 0)
        .SelectMany(x => new int[]{x, m / x })
        .Where(x => x <= m / n)
        .Max();
      Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}
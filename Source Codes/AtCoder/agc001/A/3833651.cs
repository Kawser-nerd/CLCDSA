using System;
using System.Linq;
using System.Collections.Generic;

class Program{
  static void Main()
  {
    int n = int.Parse(Console.ReadLine());
    int[] xs = 
      Console.ReadLine().Split()
      	.Select(int.Parse)
      	.OrderBy(x => x).ToArray();
    int result = 
      Enumerable.Range(0, xs.Length)
      	.Where(x => (x & 1) == 0)
      	.Select(x => xs[x])
      	.Sum();
    Console.WriteLine(result);
      	
  }
}
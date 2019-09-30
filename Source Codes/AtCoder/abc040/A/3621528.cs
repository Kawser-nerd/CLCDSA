using System;
using System.Linq;
 
class Program {
  static void Main()
  {    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(Math.Min(n[1] - 1, n[0] - n[1]));
  }
}
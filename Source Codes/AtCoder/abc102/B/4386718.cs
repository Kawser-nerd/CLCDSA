using System;
using System.Linq;

class Challenge
{
  static void Main()
  {
    var N = int.Parse(Console.ReadLine());
    var A = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
    Console.WriteLine( A.Max() - A.Min() );
  }
}
using System;
using System.Linq;

class Challenge
{
  static void Main()
  {
    var NAB = Console.ReadLine().Split();
    var N = int.Parse(NAB[0]);
    var A = int.Parse(NAB[1]);
    var B = int.Parse(NAB[2]);
    
    var count = 0;
    for (int i=0; i<=N; i++)
    {
      var n = i.ToString()
        .ToCharArray()
        .Select( x => x.ToString() )
        .Select( int.Parse )
        .ToArray()
        .Sum();
      if ( A <= n & n <= B ) count += i;
    }
    Console.WriteLine(count);
  }
}
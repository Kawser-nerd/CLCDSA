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
    
    var answer = 0;
    for (int i=0; i<=N; i++)
    {
      var n = i.ToString().Select(x => int.Parse(x.ToString())).Sum();
      if ( A <= n & n <= B ) answer += i;
    }
    Console.WriteLine(answer);
  }
}
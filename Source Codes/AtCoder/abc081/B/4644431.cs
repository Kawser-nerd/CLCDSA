using System;
using System.Linq;

class Program
{
  static void Main()
  {
    var N = int.Parse(Console.ReadLine());
    var A = Console.ReadLine().Split().Select(x => int.Parse(x));
    
    int count = 0;
    
    while(A.All( x => x%2 == 0 ))
    {
      A = A.Select( i => i/2 );
      count++;
    }

    Console.WriteLine(count);
  }
}
using System;
using System.Linq;

class Challenge
{
  static void Main()
  {
    var input = Console.ReadLine();
    var sum = input.Count( x => x == '1' );
    Console.WriteLine( sum );
  }
}
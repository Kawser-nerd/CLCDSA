using System;
using System.Linq;

class Challenge
{
  static void Main()
  {
    var input = Console.ReadLine();
    var topping = input.Count( s => s == 'o' );
    var sum = 700 + topping * 100;
    Console.WriteLine( sum );
  }
}
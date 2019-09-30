using System;

class Challenge
{
  static void Main()
  {
    var input = Console.ReadLine().Split();
    var a = int.Parse(input[0]);
    var b = int.Parse(input[1]);
    Console.WriteLine( (a+b+1)/2 );
  }
}
using System;

class Challenge
{
  static void Main()
  {
    var input = int.Parse( Console.ReadLine().Replace(" ", "") );
    Console.WriteLine( (input % 4 == 0) ? "YES" : "NO" );
  }
}
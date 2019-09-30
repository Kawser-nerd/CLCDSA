using System;

class Challenge
{
  static void Main()
  {
    var input = Console.ReadLine();
    var sum = 0;
    for (int i=0; i<3; i++)
    {
      sum += int.Parse(input[i].ToString());
    }
    Console.WriteLine( sum );
  }
}
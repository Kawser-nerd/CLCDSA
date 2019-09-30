using System;
class Program
{
  static void Main()
  {
    string[] input = Console.ReadLine().Split(' ');
    int A = int.Parse(input[0]);
    int B = int.Parse(input[1]);
    int C = int.Parse(input[2]);
    if(A + B == C)
    {
      if(A - B == C)
      {
        Console.WriteLine("?");
      }
      else
      {
        Console.WriteLine("+");
      }
    }
    else if(A - B == C)
    {
      Console.WriteLine("-");
    }
    else
    {
      Console.WriteLine("!");
    }
  }
}
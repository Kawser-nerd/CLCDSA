using System;
using System.Linq;

public class Challenge
{
  public static void Main()
  {
    var input = Console.ReadLine();
    var length = input.Length;
    var answer = input[0] + (length - 2).ToString() + input[length - 1];
    Console.WriteLine(answer);
  }
}
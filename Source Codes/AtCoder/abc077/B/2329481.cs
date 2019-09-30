using System;

class Problem
{
  public static void Main(string[] args)
  {
    var n = int.Parse(Console.ReadLine());
    var max = 0;
    for (var i = 1; i * i <= n; i++)
    {
      max = i * i;
    }
    Console.WriteLine($"{max}");
  }
}
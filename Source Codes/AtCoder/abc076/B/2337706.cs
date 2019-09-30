using System;

class Problem
{
  public static void Main(string[] args)
  {
    var n = int.Parse(Console.ReadLine());
    var k = int.Parse(Console.ReadLine());
    var min = 1;
    for (var i = 0; i < n; i++)
      min = Math.Min(min * 2, min + k);
    Console.WriteLine($"{min}");
  }
}
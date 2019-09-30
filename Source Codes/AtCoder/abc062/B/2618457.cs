using System;

class Problem
{
  public static void Main()
  {
    var inputs = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    int H = inputs[0], W = inputs[1];

    for (var i = 0; i < W+2; i++) Console.Write("#");
    Console.Write("\n");
    for (var j = 0; j < H; j++)
    {
      Console.Write("#");
      Console.Write(Console.ReadLine());
      Console.Write("#\n");
    }
    for (var k = 0; k < W+2; k++) Console.Write("#");
  }
}
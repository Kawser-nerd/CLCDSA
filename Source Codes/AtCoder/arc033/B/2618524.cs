using System;
using System.Collections.Generic;
using System.Linq;

class Classmiya
{
  public static void Main(string[] args)
  {
    string stdin = Console.ReadLine();
    stdin = Console.ReadLine();
    string[] A = stdin.Split(' ');
    stdin = Console.ReadLine();
    string[] B = stdin.Split(' ');

    string[] logicalOR = A.Union<string>(B).ToArray();
    string[] logicalAND = A.Intersect<string>(B).ToArray();

    double answer = Math.Round((double)logicalAND.Length / (double)logicalOR.Length, 10, MidpointRounding.AwayFromZero);

    Console.WriteLine(answer);
  }
}
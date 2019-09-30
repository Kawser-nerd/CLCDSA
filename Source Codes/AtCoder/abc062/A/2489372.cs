using System;
using System.Collections.Generic;

public class Problem_A
{
  static readonly HashSet<int> g1 = new HashSet<int>(new int[] { 1, 3, 5, 7, 8, 10, 12 });
  static readonly HashSet<int> g2 = new HashSet<int>(new int[] {4, 6, 9, 11});
  static readonly HashSet<int> g3 = new HashSet<int>(new int[] { 2 });

  public static void Main()
  {
    var inputs = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    int x = inputs[0], y = inputs[1];

    if (g1.Contains(x) && g1.Contains(y)
        || g2.Contains(x) && g2.Contains(y)
        || g3.Contains(x) && g3.Contains(y))
      Console.WriteLine("Yes");
    else Console.WriteLine("No");
  }
}
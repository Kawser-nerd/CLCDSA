using System;
using System.Linq;

class Program
{
  /// <summary>
  ///   ??x??????????????????????
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[,] l = new int[n,2];
    int[] x = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    Array.Sort(x);
    for (int i = 0; i < n; i ++)
    {
      l[i,0] = x[i * 2];
      l[i,1] = x[i * 2 + 1];
    }
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
      sum += Math.Min(l[i,0], l[i,1]);
    }
    Console.WriteLine(sum);
  }
}
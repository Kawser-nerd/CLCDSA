using System;
using System.Linq;

class Program
{
  /// <summary>
  ///   a(i),b(i)??????????a~b?1?????????????????
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] x = new int[1000002];
    for (int i = 0; i < n; i ++)
    {
      int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
      int a = s[0];
      int b = s[1];
      x[a] ++;
      x[b+1] --;
    }
    for (int i = 1; i < 1000001; i ++)
    {
      x[i] += x[i-1];
    }
    Console.WriteLine(x.Max());
  }
}
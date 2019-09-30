using System;
using System.Linq;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] x = new int[n];
    for (int i = 0; i < n; i ++)
    {
      x[i] = int.Parse(Console.ReadLine());
    }
    Console.WriteLine(x.Min());
  }
}
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
    int[] x = Console.ReadLine().Split(' ').Select(t => int.Parse(t)).ToArray();
    Console.WriteLine(x[1] - x[0] + 1);
  }
}
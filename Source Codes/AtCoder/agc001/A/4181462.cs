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
    int[] l = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    Array.Sort(l);
    int sum = l.Where((a, i) => i % 2 == 0).Sum();
    Console.WriteLine(sum);
  }
}
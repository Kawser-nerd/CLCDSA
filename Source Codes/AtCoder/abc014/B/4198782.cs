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
    int[] inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int n = inputs[0];
    int x = inputs[1];
    int[] prices = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int[] b = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i ++)
    {
      b[i] = x % 2;
      x /= 2;
      if (b[i] == 1) sum += prices[i];
    }
    Console.WriteLine(sum);
  }
}
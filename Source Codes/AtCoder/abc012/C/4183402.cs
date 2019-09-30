using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = 2025 - int.Parse(Console.ReadLine());
    for (int i = 1; i <= 9; i ++)
    {
      if (n % i == 0 && n/i <= 9) Console.WriteLine("{0} x {1}", i, n/i);
    }
  }
}
using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    if (n == 12) Console.WriteLine(1);
    else Console.WriteLine(n + 1);
  }
}
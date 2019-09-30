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
    if (n % 2 == 0) Console.WriteLine(n/2);
    else Console.WriteLine(n/2 + 1);
  }
}
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
    if (n % 3 == 0) Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}
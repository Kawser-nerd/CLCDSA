using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string a = Console.ReadLine();
    string b = Console.ReadLine();
    if (a.Length > b.Length) Console.WriteLine(a);
    else Console.WriteLine(b);
  }
}
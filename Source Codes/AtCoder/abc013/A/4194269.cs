using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string s = "ABCDE";
    string x = Console.ReadLine();
    Console.WriteLine(1 + s.IndexOf(x));
  }
}
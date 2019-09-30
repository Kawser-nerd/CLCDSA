using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string[] s = Console.ReadLine().Split(' ');
    int x = int.Parse(s[0]);
    int y = int.Parse(s[1]);
    Console.WriteLine(y/x);
  }
}
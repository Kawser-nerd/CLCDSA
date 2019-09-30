using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string[] s = Console.ReadLine().Split('a', 'i', 'u', 'e', 'o');
    for (int i = 0; i < s.Length; i ++) Console.Write(s[i]);
    Console.WriteLine();
  }
}
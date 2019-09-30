using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    char[] s = Console.ReadLine().ToCharArray();
    for (int i = 0; i < s.Length; i ++)
    {
      if (i == 0) s[0] = char.ToUpper(s[0]);
      else  s[i] = char.ToLower(s[i]);
    }
    Console.WriteLine(s);
  }
}
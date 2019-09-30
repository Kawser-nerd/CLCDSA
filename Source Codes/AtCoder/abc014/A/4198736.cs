using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int count = 0;
    if (a % b == 0) Console.WriteLine(0);
    else
    {
      for (int i = 0; i < a; i ++)
      {
        a ++;
        count ++;
        if (a % b == 0) break;
      }
      Console.WriteLine(count);
    }
  }
}
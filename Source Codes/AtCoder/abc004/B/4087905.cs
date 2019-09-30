using System;
using System.Linq;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    string[,] c = new string[4,4];
    for (int i = 0; i < 4; i++)
    {
      string[] a = Console.ReadLine().Split(' ');
      for (int j = 0; j < 4; j ++)
      {
        c[i,j] = a[j];
      }
    }
    for (int i = 3; i >= 0; i --)
    {
      for (int j = 3; j >= 0; j --)
      {
        if (j == 0) Console.WriteLine(c[i,j]);
        else Console.Write(c[i,j] + " ");
      }
    }
  }
}
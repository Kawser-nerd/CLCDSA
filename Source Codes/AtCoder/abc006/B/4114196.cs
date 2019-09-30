using System;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    long n = long.Parse(Console.ReadLine());
    long[] a = new long[n];
    for (int i = 0; i < n; i ++)
    {
      if (i == 0) a[0] += 0;
      else if (i == 1) a[1] += 0;
      else if (i == 2) a[2] += 1;
      else a[i] += (a[i-1] + a[i-2] + a[i-3]) % 10007;
    }
    Console.WriteLine(a[n-1]);
  }
}
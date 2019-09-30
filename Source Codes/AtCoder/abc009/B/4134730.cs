using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
  /// <summary>
  ///   The main entry point for the application
  /// </summary>
  [STAThread]
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    var list = new SortedSet<int>();
    for (int i = 0; i < n; i++)
    {
      list.Add(int.Parse(Console.ReadLine()));
    }
    int count = 0;
    foreach (int i in list)
    {
      count ++;
      if (count == list.Count() - 1) Console.WriteLine(i);
    }
  }
}
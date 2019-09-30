using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    double[]TX = Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
    double ans = TX[0]/TX[1];
    Console.WriteLine(ans);
  }
}
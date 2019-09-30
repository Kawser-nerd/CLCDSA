using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = s[0];
    int k = s[1];
    double[] r = Console.ReadLine().Split().Select(double.Parse).ToArray();
    Array.Sort(r);
    double c = 0;
    for (int i = n-k; i < n; i ++) {
      c = (c + r[i])/2;
    }
    Console.WriteLine(c);
  }
}
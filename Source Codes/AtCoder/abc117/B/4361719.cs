using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] l = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Array.Sort(l);
    int sum = 0;
    for (int i = 0; i < n-1; i ++) {
      sum += l[i];
    }
    if (l[n-1] >= sum) Console.WriteLine("No");
    else Console.WriteLine("Yes");
  }
}
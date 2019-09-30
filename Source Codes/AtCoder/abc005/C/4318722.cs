using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
  public static void Main(string[] args)
  {
    int t = int.Parse(Console.ReadLine());
    int n = int.Parse(Console.ReadLine());
    List<int> a = Console.ReadLine().Split().Select(int.Parse).ToList();
    int m = int.Parse(Console.ReadLine());
    List<int> b = Console.ReadLine().Split().Select(int.Parse).ToList();
    int count = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < b.Count(); j ++) {
        if(b[j] - a[i] <= t && b[j] - a[i] >= 0) {
          count ++;
          b.RemoveAt(j);
          break;
        }
      }
    }
    Console.WriteLine(count == m ? "yes" : "no");
  }
}
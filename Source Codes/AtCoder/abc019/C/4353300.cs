using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    HashSet<int> list = new HashSet<int>();
    for (int i = 0; i < n; i ++) {
      while(true) {
        if (a[i] % 2 == 1) {
          list.Add(a[i]);
          break;
        }
        a[i] /= 2;
      }
    }
    Console.WriteLine(list.Count());
  }
}
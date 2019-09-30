using System;
using System.Collections.Generic;
using System.Linq;
 
class Program
{
  static void Main(string[] args){
    int n = int.Parse(Console.ReadLine());
    List<int> h = Console.ReadLine().Split().Select(int.Parse).ToList();
    Console.WriteLine(solve(h,n));
  }
  static int solve(List<int> h, int n) {
    h.Insert(0, 0);
    int count = 0;
    for (int i = 1; i < h.Count; i++) {
      if (h[i] > h[i - 1]) {
        count += h[i] - h[i - 1];}
        }
    return count;
  }
}
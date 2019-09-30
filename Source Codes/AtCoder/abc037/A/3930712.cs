using System;
using System.Linq;

class P{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int cnt = 0;
    cnt += n[2] / Math.Min(n[0], n[1]);
    n[2] -= Math.Min(n[0], n[1]) * cnt;
    cnt += n[2] / Math.Max(n[0], n[1]);
    Console.WriteLine(cnt);
  }
}
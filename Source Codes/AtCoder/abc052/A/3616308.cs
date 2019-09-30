using System;
using System.Linq;

class p{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(n[0] * n[1] >= n[2] * n[3] ? n[0] * n[1] : n[2] * n[3]);
  }
}
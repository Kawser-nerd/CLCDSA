using System;
using System.Linq;

class prog{
  static void Main(){
    int[] N = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = 100 * N[0] + 10 * N[1] + N[2];
    Console.WriteLine(n % 4 == 0 ? "YES" : "NO");
  }
}
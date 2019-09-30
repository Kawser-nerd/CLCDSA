using System;
using System.Linq;

class P{
  static void Main(){
    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int N = n[0];
    int K = n[1];
    
    Console.WriteLine(N - K + 1);
  }
}
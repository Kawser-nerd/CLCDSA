using System;
using System.Linq;

class p{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    int[] T = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int M = int.Parse(Console.ReadLine());
    int[] P = new int[M];
    int[] X = new int[M];
    
    for(int i = 0; i < M; i++){
      int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
      P[i] = input[0];
      X[i] = input[1];
    }
    
    int sum = T.Sum();
    for(int i = 0; i < M; i++){
      Console.WriteLine(sum - T[P[i] - 1] + X[i]);
    }
  }
}
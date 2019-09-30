using System;
using System.Linq;

class prog{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    int K = int.Parse(Console.ReadLine());
    int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
    
    int sum = 0;
    for(int i = 0; i < N; i++){
      sum += 2 * Math.Min(Math.Abs(x[i]), Math.Abs(x[i] - K));
    }
    
    Console.WriteLine(sum);
  }
}
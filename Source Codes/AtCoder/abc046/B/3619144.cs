using System;
using System.Linq;
 
class P{
  static void Main(){
    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int N = n[0];
    int K = n[1];
    long ans = K;
    for(int i = 0; i < N - 1; i++){
      ans *= K - 1;
    }
    Console.WriteLine(ans);
       
  }
}
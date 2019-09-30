using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int D = input[0];
    int N = input[1];
    
    int ans;
    if(D == 0) ans = (N == 100) ? 101 : N;
    else if(D == 1) ans = (N == 100) ? 10100 : 100 * N;
    else ans = (N == 100) ? 1010000 : 10000 * N;
    
    Console.WriteLine(ans);
    
  }
}
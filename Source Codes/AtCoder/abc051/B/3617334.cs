using System;
using System.Linq;

class p{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int K = n[0];
    int S = n[1];
    int ans = 0;
    for(int x = 0; x <= K&&x <= S; x++){
      for(int y = 0; y <= S - x&&y <= K; y++){
        if(S - x - y >= 0&&S - x - y <= K) ans++;
      }
    }
    Console.WriteLine(ans);
  }
}
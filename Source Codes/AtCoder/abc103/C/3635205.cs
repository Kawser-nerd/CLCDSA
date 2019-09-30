using System;
using System.Linq;

class prog{
  static void Main(){
    
    int N = int.Parse(Console.ReadLine());
    int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
    
    int ans = 0;
    for(int i = 0; i < N; i++){
      ans += a[i] - 1;
    }
    
    Console.WriteLine(ans);
    
  }
}
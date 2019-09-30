using System;
using System.Linq;
 
class Program {
  static void Main()
  {    
    long[] n = Console.ReadLine().Split().Select(long.Parse).ToArray();
    long ans = 1;
    for(int i = 0; i < 3; i++){
      ans = (ans * n[i]) % 1000000007;
    }
    Console.WriteLine(ans);
  }
}
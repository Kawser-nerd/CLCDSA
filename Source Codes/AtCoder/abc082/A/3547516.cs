using System;
using System.Linq;
 
class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int ans = (input[0] + input[1]) % 2 == 0 ? (input[0] + input[1]) / 2 : (input[0] + input[1]) / 2 + 1;
    
    Console.WriteLine(ans);
  }
}
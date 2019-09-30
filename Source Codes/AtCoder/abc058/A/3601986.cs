using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(n[1] - n[0] == n[2] - n[1] ? "YES" : "NO");
    
  }
}
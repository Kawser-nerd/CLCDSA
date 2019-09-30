using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int[] num = new int[n[0] + 1];
    for(int i = 0; i <= n[0]; i++){
      num[i] = 0;
    }
    
    for(int i = 0; i < n[1]; i++){
      int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
      num[input[0]]++;
      num[input[1]]++;
    }
    
    for(int i = 1; i <= n[0]; i++){
      Console.WriteLine(num[i]);
    }
    
    
  }
}
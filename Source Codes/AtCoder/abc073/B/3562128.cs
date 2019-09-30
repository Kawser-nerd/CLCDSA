using System;
using System.Linq;

class prog{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    int[] l = new int[N];
    int[] r = new int[N];
    for(int i = 0; i < N; i++){
      int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
      l[i] = input[0];
      r[i] = input[1];
    }
    
    int sum = 0;
    for(int i = 0; i < N; i++){
      sum += r[i] - l[i] + 1;
    }
    
    Console.WriteLine(sum);
  }
}
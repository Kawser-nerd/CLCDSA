using System;
using System.Linq;

class p{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int H = n[0];
    string[] C = new string[H];
    for(int i = 0; i < H; i++){
      C[i] = Console.ReadLine();
    }
    
    for(int i = 0; i < H; i++){
      Console.WriteLine(C[i]);
      Console.WriteLine(C[i]);
    }
  }
}
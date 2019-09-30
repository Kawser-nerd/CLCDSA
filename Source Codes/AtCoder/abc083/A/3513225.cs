using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] w = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine((w[0] + w[1] > w[2] + w[3]) ? "Left" : (w[0] + w[1] == w[2] + w[3]) ? "Balanced" : "Right");
    
  }
}
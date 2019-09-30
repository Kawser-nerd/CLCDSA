using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = input[0];
    int a = input[1];
    int b = input[2];
    
    int plan1 = n * a;
    int plan2 = b;
    
    Console.WriteLine(Math.Min(plan1, plan2));
    
  }
}
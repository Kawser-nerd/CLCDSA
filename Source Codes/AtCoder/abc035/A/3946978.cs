using System;
using System.Linq;

class P{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    if(n[0] / 4 == n[1] / 3) Console.WriteLine("4:3");
    else Console.WriteLine("16:9");
  }
}
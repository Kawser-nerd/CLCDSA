using System;
using System.Linq;

class prog{
  static void Main(){
   int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int i = 0;
    Console.WriteLine(input[0] - input[1] >= 0 ? input[0] - input[1] : i);
  }
}
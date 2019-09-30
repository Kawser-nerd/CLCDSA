using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine((input[0] - 1) * (input[1] - 1));
  }
}
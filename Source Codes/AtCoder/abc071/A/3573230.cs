using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(Math.Abs(input[0] - input[1]) > Math.Abs(input[0] - input[2]) ? "B" : "A");
  }
}
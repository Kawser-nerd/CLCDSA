using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(input[0] == input[1] ? input[2] : input[1] == input[2] ? input[0] : input[1]);

  }
}
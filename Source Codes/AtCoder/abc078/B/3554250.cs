using System;
using System.Linq;

class prog{
  static void Main(){
    int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int X = input[0];
    int Y = input[1];
    int Z = input[2];
    
    Console.WriteLine((X - Z) / (Y + Z));
  }
}
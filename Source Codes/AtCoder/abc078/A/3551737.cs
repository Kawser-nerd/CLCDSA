using System;
using System.Linq;

class prog{
  static void Main(){
    string[] input = Console.ReadLine().Split().ToArray();
    int X = input[0].CompareTo(input[1]);
    Console.WriteLine(X == 1 ? ">" : X == 0 ? "=" : "<");
  }
}
using System;
using System.Linq;

class prog{
  static void Main(){
    
    string[] input = Console.ReadLine().Split().ToArray();
    Console.WriteLine(input[0][input[0].Length-1] == input[1][0]&&input[1][input[1].Length-1] == input[2][0] ? "YES" : "NO");
  }
}
using System;
using System.Linq;

class prog{
  static void Main(){
    string[] input = Console.ReadLine().Split().ToArray();
    Console.WriteLine((input[0] == "H"&&input[1] == "H")||(input[0] == "D"&&input[1] == "D") ? "H" : "D");
    
  }
}
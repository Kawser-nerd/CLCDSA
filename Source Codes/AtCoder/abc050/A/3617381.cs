using System;
using System.Linq;

class p{
  static void Main(){
    string[] n = Console.ReadLine().Split().ToArray();
    int a = int.Parse(n[0]);
    int b = int.Parse(n[2]);
    
    Console.WriteLine(n[1] == "+" ? a + b : a - b);
  }
}
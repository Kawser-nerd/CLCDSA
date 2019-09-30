using System;
using System.Linq;

class Program{
  static void Main(string[] args){
    
    Console.ReadLine();
    int a = Console.ReadLine().Replace(" ","").Distinct().Count();
    Console.WriteLine(a == 3 ? "Three" : "Four");
    
  }
}
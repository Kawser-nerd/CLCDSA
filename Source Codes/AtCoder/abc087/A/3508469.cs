using System;
using System.Linq;

class prog{
  static void Main(){
    
    int x = int.Parse(Console.ReadLine());
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    
    Console.WriteLine((x - a) % b);
    
  }
}
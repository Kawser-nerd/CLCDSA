using System;
using System.Linq;

class prog{
  static void Main(){
    
    int n = int.Parse(Console.ReadLine());
    int a = int.Parse(Console.ReadLine());
    
    Console.WriteLine(a >= n % 500 ? "Yes" : "No");
    
  }
}
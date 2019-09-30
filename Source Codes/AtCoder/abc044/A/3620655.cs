using System;
using System.Linq;

class p{
  static void Main(){
    int n = int.Parse(Console.ReadLine());
    int k = int.Parse(Console.ReadLine());
    int x = int.Parse(Console.ReadLine());
    int y = int.Parse(Console.ReadLine());
    
    Console.WriteLine(n <= k ? n * x : k * x + (n - k) * y);
    
  }
}
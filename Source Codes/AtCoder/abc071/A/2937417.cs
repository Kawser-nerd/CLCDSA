using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int x = int.Parse(input[0]);
    int a = int.Parse(input[1]);
    int b = int.Parse(input[2]);
    
    int xa, xb;
    
    if(x < a) xa = a - x;
    else xa = x - a;
    
    if(x < b) xb = b - x;
    else xb = x - b;
    
    if(xa < xb) Console.WriteLine("A");
    else Console.WriteLine("B");
  }
}